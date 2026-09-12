#include<iostream>
#include<string>
#define Max 1000
using namespace std;
class Patient 
{  private:
    int id ;
    string name;
    int age;
    int severity;
    string symptoms;
    string arrival_time;
 public :
    Patient(){
        id=0;
        name="";
        age=0;
        severity=0;
        symptoms="";
        arrival_time ="";
    }
    Patient (int p_id,string n,int p_age ,string sy, int se,string  a_t){
        id = p_id;
        name= n;
        age = p_age;
        symptoms = sy;
        severity = se;
        arrival_time = a_t;
    }
    Patient ( const Patient& p){
     id = p.id;
     name = p.name;
     age= p.age;
     severity = p.severity;
     symptoms= p.symptoms;
     arrival_time = p.arrival_time;
    }
     int getSeverity()
    {
        return severity;
    }
     int getArrivalTime()
{
    int h = stoi(arrival_time.substr(0, 2));
    int m = stoi(arrival_time.substr(3, 2));
    int s = stoi(arrival_time.substr(6, 2));
      return h * 3600 + m * 60 + s;
}
    void display () {
        cout<<"-----Patient Detail-----"<< endl;
        cout<<"ID: "<< id<< endl;;
        cout<<"Name of the patient: "<<name<<endl;
        cout<<"Age : "<<age << endl;
        cout<<"Symptoms  of the patient: "<<symptoms<<endl;
        cout<<"Severity : "<<severity <<endl;
        cout<<"Arrival time :"<<arrival_time<<endl;}
};
class EmergencyPatient : public Patient{
    public:
    EmergencyPatient(int p_id,string n ,int p_age,string sy,int se,string a_t):Patient(p_id,n,p_age,sy,se,a_t){
}
};
class FollowupPatient : public Patient{
    public:
    FollowupPatient(int p_id,string n ,int p_age,string sy,int se,string a_t):Patient(p_id,n,p_age,sy,se,a_t){
}
};
class RoutinePatient : public Patient{
    public:
    RoutinePatient(int p_id,string n ,int p_age,string sy,int se,string a_t):Patient(p_id,n,p_age,sy,se,a_t){
 }
};
struct PriorityQueue
{
    Patient patients[Max];
    int size;
    void enqueue(Patient p){
        if( size==Max){
            cout<<"Queue is Overflow"<<endl;
            return;
        }
        int i = size-1;
        while(i>=0 && (p.getSeverity()<patients[i].getSeverity() || (p.getSeverity()==patients[i].getSeverity() && p.getArrivalTime()<patients[i].getArrivalTime())))
        {
            patients[i+1]=patients[i];
            i--;
        }
       patients[i+1]=p;
       size++;}
    void dequeue(){
    if (size == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "\nPatient treated:" << endl;
    patients[0].display();
    for (int i = 0; i < size - 1; i++)
    {
        patients[i] = patients[i + 1];
    }
     size--;
}
bool isEmpty()
{
    return size == 0;
}
   void display(){
        if (size==0){
            cout<<"Queue is empty"<< endl;
            return;

        }
        cout<<"\n----Patients Priority Queue----"<<endl;
        for(int i=0;i<size;i++){
            cout<<"Patient"<< i+1<<":"<<endl;
            patients[i].display();
        }
    }
    void peek()
{
    if (size == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "\nPatient with highest priority:" << endl;
    patients[0].display();
}
};
int main()
{
    int n;
    cout << "Enter number of patients: ";
    cin >> n;
    PriorityQueue q;
    q.size = 0;
   for (int i = 0; i < n; i++){
    int id, age, severity; 
    string name, symptoms,arrival_time;
     cout << "\nEnter details of Patient " << i + 1 << endl;
     cout << "Patient ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Symptoms: ";
    cin >> symptoms;
    cout << "Severity (1-5): ";
    cin >> severity;
    cout << "Arrival time (HHMMSS): ";
    cin >> arrival_time;
 Patient p(id, name, age, symptoms, severity, arrival_time);
    q.enqueue(p);
}
  cout << "\n--- Patients Priority Queue ---" << endl;
    q.display();
    q.peek();
    q.dequeue();
   if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}