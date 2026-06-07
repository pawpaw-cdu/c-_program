#include <iostream>
#include <string>
#include <iomanip>

class Student{
    private:
        std::string id;
        std::string name;
        int age;
        double scores[3];

    public:
        Student(std::string stuId,std::string StuName,int stuAge,
                double score1,double score2,double score3){
                    this->id = stuId;
                    this->name = StuName;
                    age = stuAge;
                    scores[0] = score1;
                    scores[1] = score2;
                    scores[2] = score3;
                }

        double getTotalScore() const {
            return (scores[0]+scores[1]+scores[2]);
        }

        double getAverageScore() const {
            return (scores[0]+scores[1]+scores[2])/3;
        }

        void displayInfo() const {
            std::cout<<"学号:"<<""<<this->id<<std::endl;
            std::cout<<"姓名:"<<""<<this->name<<std::endl;
            std::cout<<"年龄:"<<age<<std::endl;
            std::cout<<"三科成绩："<<scores[0]
                   <<" "<<scores[1]<<" "<<scores[2]<<std::endl;
        }

        double getAvg() const {
            return getAverageScore();
        }

        std::string getName() const {
            return this->name;
        }
};

int main(){
    Student stu1("202601","张三",18,92.0,91.8,90.6);
    Student stu2("202602","李四",19,90.1,92.8,92.6);
    Student stu3("202603","王五",20,92.5,91.4,89.6);

    std::cout<<"=== 学生信息 ==="<<std::endl;
    stu1.displayInfo();
    stu2.displayInfo();
    stu3.displayInfo();

    const Student* students[] = {&stu1,&stu2,&stu3};
    const Student* topStudent = students[0];

    for(int i = 0;i < 3;i++){
        if(students[i]->getAvg() > topStudent->getAvg()){
            topStudent = students[i];
        }
    }

    std::cout<<"=== 平均分最高的学生 ==="<<std::endl;
    std::cout<<"姓名："<<topStudent->getName()<<"平均分："<<topStudent->getAvg()<<std::endl;

    return 0;
}