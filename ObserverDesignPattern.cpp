#include <iostream>
#include <set>
using namespace std;

class Observer {
    public:
    virtual void update() = 0;
};

class StockObservable {
    public:
    virtual void add(Observer* item) = 0;
    virtual void remove(Observer* item) = 0;
    virtual void notify() = 0;
    virtual void setStock(int cu) = 0;
    virtual int getStockCount() = 0;
};

class MobileObserver : public Observer {
    private:
    string mobileNo;
    StockObservable* observable;
    public:
    MobileObserver(string number, StockObservable* stock) : mobileNo(number), observable(stock) {}; 

    void update() {
        cout<<"mobile Update "<<mobileNo<<" "<<observable->getStockCount()<<endl;
    }
};

class EmailObserver : public Observer {
    private:
    string email;
    StockObservable* observable;
    public:
    EmailObserver(string number, StockObservable* stock) : email(number), observable(stock) {}; 

    void update() {
        cout<<"Email Update "<<email<<" "<<observable->getStockCount()<<endl;
    }
};

class IphoneObservable : public StockObservable {
    private:
    set<Observer*> st;
    int stockCount = 0;
    public:
    void add(Observer* item) {
        st.insert(item);
    }

    void remove(Observer* item) {
        st.erase(item);
    }

    void notify() {
        for(auto x:st) {
            x->update();
        }
    }

    void setStock(int cu) {
       stockCount = cu;
    }

    int getStockCount() {
        return stockCount;
    }
};

class SamsungObservable : public StockObservable {
    private:
    set<Observer*> st;
    int stockCount = 0;
    public:
    void add(Observer* item) {
        st.insert(item);
    }

    void remove(Observer* item) {
        st.erase(item);
    }

    void notify() {
        for(auto x:st) {
            x->update();
        }
    }

    void setStock(int cu) {
       stockCount = cu;
    }

    int getStockCount() {
        return stockCount;
    }
};

int main() {
    StockObservable* iphoneStock = new IphoneObservable();
    StockObservable* samsungStock = new SamsungObservable();

    iphoneStock->add(new EmailObserver("@.com", iphoneStock));
    iphoneStock->add(new MobileObserver("224", iphoneStock));
    iphoneStock->setStock(100);
    iphoneStock->notify();

    samsungStock->add(new EmailObserver("123@.com", samsungStock));
    samsungStock->add(new MobileObserver("123224", samsungStock));
    samsungStock->setStock(10);
    samsungStock->notify();
    return 0;
}