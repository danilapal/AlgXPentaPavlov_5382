#ifndef ALGORITNMX_H
#define ALGORITNMX_H

#include <functional>
#include <string>
#include <vector>

class AlgorithmX
{
public:
    AlgorithmX();
    ~AlgorithmX();

    using solution_t = std::vector<std::vector<std::string>>;
    using solution_cb_t = std::function<void(const solution_t&)>;
    void search(const std::string &fn, solution_cb_t solution_cb);

private:
    class Column;
    class Node {
    public:
        virtual ~Node() = default;

        Node* left{ nullptr };
        Node* right{ nullptr };
        Node* up{ nullptr };
        Node* down{ nullptr };
        Column* column{ nullptr };
    };

    class Column : public Node {
    public:
        std::string name;
        size_t size{ 0 };
    };

    void search(std::vector<Node*> &a, const solution_cb_t& solution_cb);
    void handle_solution(const std::vector<Node*>& solution,
                         const solution_cb_t& solution_cb);
    void cover_column(Column* c);
    void uncover_column(Column* c);
    Column* choose_column();

    void load(const std::string &fileName);
    void clear();
    bool empty() const;

    Column root_;
};

#endif // ALGORITNMX_H
