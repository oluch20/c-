#include<iostream>

using namespace std;

enum State{
    OK,
    DIV0,
    OUT_OF_BOUNDS
};


class myInteger{
    public:
        int value;
        myInteger(int v){
            this->value = v;
        }

        myInteger add(myInteger a, State &s){
            s = OK;
            return myInteger(this->value+a.value);
        }


        myInteger div(myInteger a, State &s){
            if(a.value == 0){
                s = DIV0;
            }else{
                s = OK;
            }
            return myInteger(a.value ==  0 ? 0 : this->value / a.value);
        }
};


class myReal{
    public:
        float value;
        myReal(float v){
            this->value = v;
        }

        myReal add(myReal a, State &s){
            s = OK;
            return myReal(this->value+a.value);
        }

        myReal div(myReal a, State &s){
            if(a.value == 0){
                s = DIV0;
            }else{
                s = OK;
            }
            return myReal(a.value ==  0 ? 0 : this->value / a.value);
        }
};


class myCalc{
    private:
        State state = OK;
    public:
        void setState(State s){
            this->state = s;
        }
        State getState(){
            return this->state;
        }

        string getReadableState(){
            switch(this->state){
                case OK: return "OK"; break;
                case DIV0: return "division by 0 error"; break;
                case OUT_OF_BOUNDS: return "działanie poza zakresem"; break;
                default: return "nieznany stan"; break;
            }
        }
};

int main(){
    
    State s;
    myCalc c = myCalc();
    myInteger a  = myInteger(5);
    myInteger b  = myInteger(0);

    cout << "result: " << (a.add(b, s)).value << endl;
    c.setState(s);
    cout << "state: " << c.getReadableState() << endl;
    return c.getState();
}