#include <iostream>
#include <list>
using namespace std;

//constexpr vs const: constexpr variables must be initialized at compile time while const variables are initialized at run time
constexpr int SPECIALIZATIONS = 20;
constexpr int QUEUE_SIZE = 5;

struct Patient{
    Patient(const string& name, int status): m_name(name), m_status(status){
    }
    string m_name;
    int m_status = 0;
};

class HospitalSys
{
public:
    HospitalSys(){}

    bool addPatient(const string& name, const int status, int specialization){
        auto p = make_shared<Patient>(name, status);
        specialization--;
        if(m_patientQ[specialization].size() == QUEUE_SIZE){
            return false;
        }
        if(status == 1){
            m_patientQ[specialization].push_front(p);
        }
        else{
            m_patientQ[specialization].push_back(p);
        }
        return true;
    }

    void printPatients(){
        for(int i=0; i<SPECIALIZATIONS; i++){
            auto queue = m_patientQ[i];
            if(queue.size()>0){
                cout << "There are " << queue.size() << " patients in specialization " << i+1 << endl;
                for(const auto p: queue){
                    string priority = p->m_status == 1? "urgent" : "regular";
                    cout << p->m_name << " " << priority <<endl;
                }
            }
        }
    }

    bool getNextPatient(int specialization){
        auto& queue = m_patientQ[specialization-1];
        if(queue.size() == 0){
            cout<< "No patients at the moment." << endl;
            return false;
        }
        auto p = queue.front();
        cout << p->m_name << " please go with the doctor." << endl;
        queue.pop_front();
        cout<<queue.size()<<endl;

        return true;
    }

private:
    list<shared_ptr<Patient>> m_patientQ [SPECIALIZATIONS];
};

int main()
{
    //new only for pointer
    HospitalSys system;
    while(1){
        cout << "Enter your choice: " << endl
        << "1. Add Patient" << endl
        << "2. Print all Patients" << endl
        << "3. Get new Patient" << endl
        << "4. Exit" << endl;

        int userInput, specialization;
        cin >> userInput;
        if(userInput == 1){
            string name;
            int status;
            cout << "Enter specialization, name, status: ";
            cin >> specialization >> name >> status;
            cout << endl;
            system.addPatient(name, status, specialization);
        }
        else if(userInput == 2){
            system.printPatients();
        }
        else if(userInput == 3){
            cout << "Enter specialization: ";
            cin >> specialization;
            cout << endl;
            system.getNextPatient(specialization);
        }
        else if(userInput == 4){
            cout << "Goodbye." << endl;
            break;
        }
    }
    return 0;
}