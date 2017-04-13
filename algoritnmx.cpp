#include "algoritnmx.h"

#include <climits>
#include <fstream>
#include <iostream>

AlgorithmX::AlgorithmX()
{
    root_.right = &root_;
}

AlgorithmX::~AlgorithmX()
{
    clear();
}

void AlgorithmX::search(const std::string &fn, solution_cb_t solution_cb)
{
    load(fn);
    std::vector<Node*> solution;
    search(solution, solution_cb);
    clear();
}

void AlgorithmX::search(std::vector<Node*> &solution,
                     const solution_cb_t& solution_cb)
{
    if(empty()) { // solution is found
        handle_solution(solution, solution_cb);
        return;
    }

    Column* col = choose_column();

    cover_column(col);

    for(Node* row = col->down; row != col; row = row->down) {
        solution.push_back(row);

        for(Node* node = row->right; node != row; node = node->right)
            cover_column(node->column);

        search(solution, solution_cb);

        for(Node* node = row->left; node != row; node = node->left)
            uncover_column(node->column);

        solution.pop_back();
    }

    uncover_column(col);
}

void AlgorithmX::handle_solution(const std::vector<Node*> &a,
                              const solution_cb_t& solution_cb)
{
    solution_t solution(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        Node* r;
        for (r = a[i]; r->right != a[i]; r = r->right)
            solution[i].push_back(r->column->name);
        solution[i].push_back(r->column->name);
    }
    solution_cb(solution);
}

void AlgorithmX::cover_column(Column* c)
{
    c->right->left = c->left;
    c->left->right = c->right;

    for (Node* i = c->down; i != c; i = i->down) {
        for (Node* j = i->right; j != i; j = j->right) {
            j->down->up = j->up;
            j->up->down = j->down;
            j->column->size--;
        }
    }
}

void AlgorithmX::uncover_column(Column* c)
{
    for (Node* i = c->up; i != c; i = i->up) {
        for (Node* j = i->left; j != i; j = j->left) {
            j->column->size++;
            j->down->up = j;
            j->up->down = j;
        }
    }

    c->right->left = c;
    c->left->right = c;
}

AlgorithmX::Column* AlgorithmX::choose_column()
{
    size_t min_size = UINT_MAX;
    Column* min_column = nullptr;
    for(Column* col = dynamic_cast<Column*>(root_.right);
            col != &root_;
            col = dynamic_cast<Column*>(col->right)) {
        if(col->size < min_size) {
            min_size = col->size;
            min_column = col;
        }
    }
    return min_column;
}

void AlgorithmX::load(const std::string &fn)
{
    if (!empty()) clear();

    std::ifstream fin(fn.c_str());
    if(!fin.is_open()) {
        throw std::runtime_error("File " + fn + " is not opened");
    }

    size_t col_num;
    fin >> col_num;

    std::vector<Node*> last_nodes(col_num);
    std::vector<Column*> headers(col_num);

    Column* prev_col = &root_;
    for (size_t i = 0; i < col_num; ++i) {
        Column* col = new Column();
        col->left = prev_col;
        col->up = col;
        col->down = col;
        col->column = col;
        fin >> col->name;

        prev_col->right = col;
        prev_col = col;

        last_nodes[i] = col;
        headers[i] = col;
    }

    prev_col->right = &root_;
    root_.left = prev_col;

    size_t row_len;
    Node* prev_node;
    while (fin >> row_len) {
        prev_node = nullptr;
        size_t col;
        for (size_t j = 0; j < row_len; ++j) {
            fin >> col;
            Node* node = new Node();
            if (prev_node == nullptr) {
                prev_node = node;
                node->left = node;
                node->right = node;
            }

            node->column = headers[col];

            node->right = prev_node->right;
            node->left = prev_node;
            prev_node->right->left = node;
            prev_node->right = node;

            node->down = last_nodes[col]->down;
            node->up = last_nodes[col];
            last_nodes[col]->down->up = node;
            last_nodes[col]->down = node;

            headers[col]->size++;
            last_nodes[col] = node;

            prev_node = node;
        }
    }
    std::cerr << "loaded";
}

void AlgorithmX::clear() {
    // todo: clear matrix
}

bool AlgorithmX::empty() const
{
    return root_.right == &root_;
}
