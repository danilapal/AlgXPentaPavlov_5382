#ifndef SHAPE_H
#define SHAPE_H
#include <fstream>
#include <iostream>
struct basePantaShape
{
    basePantaShape () {}
    basePantaShape(int array[],int k)
    {
        if (k==5) {
            for(int i=0;i<5;++i)
                squareshape[i]=array[i];
        }

    }
    int getVal(int k)
    {
        if(k<5) return  squareshape[k];
    }
    void  baseShow() const
    {
        for (int i=0 ;i<5;++i)
            std::cout<< squareshape [i] << std::endl;

    }
private:
    int squareshape [5];



};
class PentaShape
{
public:
    PentaShape() {}
    PentaShape (basePantaShape shape, int Type)
    {
        //обнуление
        for (int i=0 ;i<5;i++) {
            for (int q=0 ;q<5;q++){
                field[i][q]=0;
            }
        }
        int current=0;

        for (int k=0;k<5;k++) {
            current=shape.getVal(k);
            // std::cout<<"CURRENT="<<current<<std::endl;

            for (int i=0 ;i<5;i++) {
                for (int q=0 ;q<5;q++){
                    if ((current/5==i)&&(current%5==q))
                    { //std::cout<<"CHECK"<<std::endl;
                        field[i][q]=1;

                    }

                }
            }
        }
        Type_=Type;
    }
    ~PentaShape(){ }
    int getVal(int i,int q);
    int getH() const;
    int getD() const;
    void countVariant(std::ofstream &in, int h, int w);
    void show ()
    {
        std::cout<< "TYPE " <<Type_<<std::endl;
        for (int i=0 ;i<5;i++) {
            for (int q=0 ;q<5;q++) {

                if (field[i][q]==1) {
                    std::cout<<i<<" "<<q<<std::endl;

                }
            }
        }
    }
    void fortest()
    {

        std::cout<<"HAHA"<<varit [6].variantarray [2] [3];

    }
private:
    void replaceInCorner();
    void inputFile (std::ofstream &in , int h, int w);
    void reverseShapeVertical() ;
    void reverseShapeHorizontal() ;
    void turnRight();

    int field [5][5];
    int Type_;
    struct allvariants
    {
        int variantarray [5] [5];
        allvariants()
        {

            for (int i=0;i<5;++i) {
                for(int j = 0; j < 5; ++j)
                    variantarray [i] [j]=0;

            }
        }
    };
    allvariants varit [8];

    bool eqqualization (int &counter) {

        int partsSame=0;
        for (int c=0 ;c<=counter;c++) {

            for (int i=0 ;i<5;i++) {
                for(int q=0 ;q<5; q++) {
                    if ((varit [c].variantarray[i] [q]==field [i] [q]) && (field [i] [q]==1)) {

                        partsSame++;

                    }

                }

            }
            if (partsSame==5) {
                //    std::cout<<"FAIL OLD VERSION"<<std::endl;
                return false;
            }
            else partsSame=0;

        }
        counter++;
        for (int i=0 ;i<5;i++) {
            for(int q=0 ;q<5; q++) {
                varit [counter].variantarray [i] [q]=field [i] [q];

            }
        }

        return true;



    }
};
int PentaShape:: getVal(int i,int q)
{
    return field [i] [q];
}

void PentaShape:: replaceInCorner()
{
    int minx=-1;
    int miny=-1;
    for (int i=0 ;i<5;i++) {
        for (int q=0 ;q<5;q++) {
            if ((miny<i)&&(field [i] [q]==1))
                miny=i;
            if ((minx<q)&&(field[i] [q]==1))
                minx=q;
        }
    }


    int save [5] [5];
    for (int i=0 ;i<5;i++) {
        for (int q=0 ;q<5;q++){
            save [i] [q]=0;
        }
    }

    /*  for (int i=0 ;i<5;i++) {
        for (int q=0 ;q<5;q++){
            if (field [i] [q]==1) {
                field[i][q]=0;
                field [i-miny] [q-minx]=1;


            }
        }
    }
    */
    for (int i=0 ;i<5;i++) {
        for (int q=0 ;q<5;q++){
            if (field [i] [q]==1)
                save [miny-i] [minx-q]=1;
        }
    }
    for (int i=0 ;i<5;i++) {
        for (int q=0 ;q<5;q++){
            if (save [i] [q]==1)
                field [i][q]=1;
            else
                field [i] [q]=0;
        }
    }
}

void PentaShape::turnRight()
{
    int buffer [5] [5];
    for (int i=0;i<5;i++) {
        for (int q=0;q<5;q++) {
            buffer[i] [q]=field [q] [5-i-1];
        }
    }
    for (int i=0;i<5;i++) {
        for (int q=0;q<5;q++) {
            field [i] [q]=buffer[i] [q];
        }
    }

}

int PentaShape::getH() const
{

    int maxh=0;


    for (int u=0 ; u<5;u++) {

        for (int i=0;i<5;i++) {
            if ((field[i] [u]==1) &&(maxh<i))
                maxh=i;
        }


    }
    return maxh+1;
}

int PentaShape::getD() const
{

    int maxd=0;

    for (int i=0 ; i<5;i++) {

        for (int u=0;u<5;u++) {
            if ((field[i] [u]==1) &&(maxd<u))
                maxd=u;
        }


    }

    return maxd+1;

}
void PentaShape::inputFile (std::ofstream &in , int h, int w)
{   int saveLocation [5];
    int count=0;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            if (field[i] [j]==1) {
                saveLocation[count]=i*10+j;
                ++count;
            }
        }
    }

    int down=h-getH() ;
    int up=w-getD();
    int save=0;
    int n=6;
    /*
    for (int q=0; q<=down; q++) {

        in<<n<<" ";
        in<<Type_<<" ";
        for (int k=0 ; k<count; k++)
        {
            save=saveLocation[k]+10*q;
            //save=saveLocation[k]+10*q+12;
            in<<save<<" ";
        }
        in<<"\n";
    }

    for (int q=0; q<=up; q++) {
        in<<n<<"";
        in<<Type_;
        for (int k=0 ; k<count; k++)
        {   save=saveLocation[k]+q;
            //save=saveLocation[k]+10*q+12;
            in<<save<<" ";
        }
        in<<"\n";
    }
    */
    for (int q=0; q<=up; q++) {
        for (int i=0; i<=down; i++) {

            in<<n<<" ";
            in<<Type_<<" ";
            for (int k=0 ; k<5; k++) {
                save=saveLocation[k]+10*i+q+12;
                // save=saveLocation[k]+10*i+q;
                in<<save<<" ";
            }
            in<<"\n";
        }
    }


}


void  PentaShape::reverseShapeVertical()
{   int result[5][5];
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j) {
            result[i][5 - 1 - j] = field [i][j];
        }
    for (int i=0;i<5;++i) {
        for(int j = 0; j < 5; ++j)
            field[i] [j]=result[i][j];
    }

}
void  PentaShape::reverseShapeHorizontal()
{   int result[5][5];
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j)
            result[5 - 1 - i][j] = field [i][j];
    }
    for (int i=0;i<5;++i) {
        for(int j = 0; j < 5; ++j)
            field[i] [j]=result[i][j];
    }

}
void PentaShape:: countVariant(std::ofstream &in, int h, int w)
{
    int saveOriginal [5] [5];
    bool sameCheck;


    int counter=0;
    // replaceInCorner();
    //считывание
    inputFile (in,h,w);
    for (int i=0;i<5;++i) {
        for(int j = 0; j < 5; ++j) {
            saveOriginal[i] [j]=field[i] [j];
            varit [counter].variantarray[i] [j]=saveOriginal [i] [j];
        }
    }
    counter++;


    int count=2;
    while (count!=0) {
        if (count==1) {
            for (int i=0;i<5;++i) {
                for(int j = 0; j < 5; ++j)
                    field[i] [j]=saveOriginal[i][j];
            }


            turnRight();
            replaceInCorner();

            //считывание
            sameCheck=eqqualization (counter);
            if (sameCheck)
                inputFile (in,h,w);

        }
        reverseShapeHorizontal();
        replaceInCorner();
        //cчитывание
        sameCheck=eqqualization (counter);
        if (sameCheck)
            inputFile (in,h,w);
        reverseShapeVertical();
        replaceInCorner();
        //считывание
        sameCheck=eqqualization (counter);
        if (sameCheck)
            inputFile (in,h,w);
        reverseShapeHorizontal();
        replaceInCorner();
        //считывание
        sameCheck=eqqualization (counter);
        if (sameCheck)
            inputFile (in,h,w);
        count--;
    }

    for (int i=0;i<5;++i) {
        for(int j = 0; j < 5; ++j) {
            saveOriginal[i] [j]=field[i] [j];
        }
    }
    for(int z=0;z<counter;z++) {
    for (int i=0;i<5;++i) {
        for(int j = 0; j < 5; ++j) {

            varit [counter].variantarray[i] [j]=0;
        }
    }
   }

}

#endif // SHAPE_H
