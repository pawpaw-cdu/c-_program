#include <iostream>
#include <string>
#include <vector>

struct Transaction
{
    std::string type;
    double amount;
    std::string timetamp;
};

class BankAccount{
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;
    std::string password;
    std::vector<Transaction> transaction;

public:
    BankAccount(std::string accNum,std::string accHol,
                std::string pwd,double initialBalance = 0.0):
                accountNumber(accNum),
                accountHolder(accHol),
                balance(initialBalance),
                password(pwd){}
    //存款(接口)
    void depo(double amount){
        deposit(amount);
    }
    //取款(接口)
    void with(double amount,std::string pwd){
        withdra(amount,pwd);
    }
    //获取账户余额
    double getBalance() const {
        return this->balance;
    }
    //修改账户密码(接口)
    void change(std::string oldPwd,std::string newPwd){
        changePassword(oldPwd,newPwd);
    }
    //输出账户基本信息(接口)
    void prinInfo()const {
        displayAcountInfo();
    }
    //输出账户历史交易记录
    void displayTransactionHistory() const {}

private:

    bool changePassword(std::string OldPwd,std::string NewPwd){
            if(this->password != OldPwd){
                std::cout<<"修改失败!"<<std::endl;
                std::cout<<std::endl;
                return false;
            }
            this->password = NewPwd;
            std::cout<<"修改成功! "<<std::endl;
            getPassword();
            return true;
        }

    bool withdra(double amount,std::string pwd){
            if(this->password != pwd || this->balance < amount){
                std::cout<<"操作失败！"<<std::endl;
                return false;
            }
            this->balance -= amount;
            std::cout<<"操作成功！"<<std::endl;
            std::cout<<"当前账户余额为: "<<this->balance<<std::endl;
            std::cout<<std::endl;
            return true;
        }

    bool deposit(double amount){
            if(amount>0){
                this->balance += amount;
                std::cout<<"存款成功!"<<std::endl;
                std::cout<<"当前账户余额: "<<this->balance<<std::endl;
                std::cout<<std::endl;
                return true;
            }
            std::cout<<"输入金额错误!操作失败! "<<std::endl;
            return false;
        }

    void getPassword(){
        std::cout<<"当前账户密码为: "<<this->password<<std::endl;
        std::cout<<std::endl;
    }

    void displayAcountInfo() const {
            std::cout<<"账户序号: "<<this->accountNumber<<std::endl;
            std::cout<<"账户持有人: "<<this->accountHolder<<std::endl;
            std::cout<<"账户金额: "<<this->balance<<std::endl;
            std::cout<<std::endl;
        }

    void addTransaction(std::string type,double mount){}
};

int main(){
    BankAccount accountOne("1001","张三","12453");
    BankAccount accountTwo("1002","李四","13452");

    std::cout<<"=== 初始账户状态 ==="<<std::endl;
    accountOne.prinInfo();
    accountTwo.prinInfo();

    //存款操作
    accountOne.depo(500.0);
    accountOne.prinInfo();

    accountTwo.depo(600.0);
    accountTwo.prinInfo();

    //取款操作
    accountOne.with(501,"12453");
    accountOne.with(500,"12453");

    //密码修改
    accountTwo.change("13452","12345");
}