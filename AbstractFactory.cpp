#include <iostream>
using namespace std;


class IButton {
   public:
   virtual void onPress() = 0;
};

class MacBtn : public IButton {
   public:
   void onPress() {
      cout<<"macBtn"<<endl;
   }
};

class WindowBtn : public IButton {
   public:
   void onPress() {
      cout<<"WindowBtn"<<endl;
   }
};

class ITextBox {
   public:
   virtual void onType() = 0;
};

class MacTextBox : public ITextBox {
    public:
    void onType() {
        cout<<"Mac Text Box"<<endl;
    }
};

class WindowTextBox : public ITextBox {
    public:
    void onType() {
        cout<<"Window Text Box"<<endl;
    }
};

class IFactory {
    public:
    virtual IButton* CreateBtn() = 0;
    virtual ITextBox* CreateTextBox() = 0;
};

class MacFactory : public IFactory {
    public:
    IButton* CreateBtn() {
        return new MacBtn();
    }
    ITextBox* CreateTextBox() {
        return new MacTextBox();
    }
};

class WindowFactory : public IFactory {
    public:
    IButton* CreateBtn() {
        return new WindowBtn();
    }
    ITextBox* CreateTextBox() {
        return new WindowTextBox();
    }
};

class VFactory {
   public:
    static IFactory* CreateFactory(string osType) {
        if(osType == "MAC") {
            return new MacFactory();
        } else if(osType == "WINDOW") {
            return new WindowFactory();
        } 
        return new MacFactory();
    }
};

int main() {
 
    string osType;
    cin>>osType;
    IFactory* fact = VFactory::CreateFactory(osType);
    IButton* myBtn = fact->CreateBtn();
    myBtn->onPress();
    ITextBox* myTextBox = fact->CreateTextBox();
    myTextBox->onType();
    return 0;
}