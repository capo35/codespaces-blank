#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// !  /* *****************************************************linked_list************************************************************ */
typedef int elemtype;
class linked_list {
    struct node;
    typedef node * link;
    struct node{
        elemtype id,age;
        float gpa;
        string name;
        link next;
    };
    link head,tail ,current,ptrSearch;
public :
    linked_list();
    ~linked_list();
    bool first(elemtype & idd ,elemtype & agee ,float &gpaa, string &namee);
    bool next(elemtype & idd ,elemtype & agee ,float &gpaa, string &namee);
    void insert(const elemtype & idd ,const elemtype & agee ,const float &gpaa, const string &namee);
    int search(elemtype & idd ,elemtype & agee ,float &gpaa, string &namee);
    void displayAll();        
    void update(elemtype& id_old ,elemtype  idd ,elemtype  agee ,float gpaa, string namee);
    bool deleteNode(int n);      
};
    linked_list ::linked_list(){
        current = head = ptrSearch =NULL;
    }
    bool linked_list :: first(elemtype & idd ,elemtype & agee ,float &gpaa, string &namee){
        assert(head);
        if(!head) return false;
        current=head;
        idd=current->id;
        gpaa=current->gpa;
        agee=current->age;
        namee=current->name;
        return true;
    }
    bool linked_list :: next(elemtype & idd ,elemtype & agee ,float &gpaa, string &namee){
        assert(current);
        if(!current->next) return false;
        current=current->next;
        idd=current->id;
        gpaa=current->gpa;
        agee=current->age;
        namee=current->name;
        return true;
    }
    void linked_list :: insert(const elemtype & idd ,const elemtype & agee ,const float &gpaa, const string &namee){
        link add(new node);
        assert(add);
        add->id=idd;
        add->age =agee;
        add->gpa=gpaa;
        add->name=namee;
        current=head;
        if(!head)
            head=add;
        else {      
            while (current->next)
                current=current->next;
        current->next=add;  }
        add->next=NULL;
        tail=add;
    }
    int linked_list :: search(elemtype & idd ,elemtype & agee ,float &gpaa, string &namee){
        assert(head);
        int n=0;
        if(!head){
            cout<<"list is empty";
            return -1;
        } 
        for(ptrSearch =head ; ptrSearch; ptrSearch=ptrSearch->next){
            if(ptrSearch->id==idd){
                gpaa=ptrSearch->gpa;
                agee=ptrSearch->age;
                namee=ptrSearch->name;
                return n;  
            }
            n++;
        }
        cout<<"Student not found\n";
        return -1;
    }
    void linked_list :: displayAll(){
        assert(head);
        if(!head){
            cout<<"list is empty !";
        return;}
        for(link ptr =head ; ptr ; ptr=ptr->next){
            cout<<"Student name : "<<ptr->name<<"\nStudent Id : "<<ptr->id<<"\nStudent GPA : "<<ptr->gpa<<"\nStudent Age : "<<ptr->age<<endl;
        }
    }
    void linked_list :: update(elemtype & id_old ,elemtype  idd ,elemtype  agee ,float gpaa, string namee){
        int x; float y; string z;
        int n=search(  id_old ,x , y, z );
        if(n<0)
            return;
        else{    
        ptrSearch->gpa=gpaa;
        ptrSearch->age=agee;
        ptrSearch->name=namee;            
        ptrSearch->id=idd;
        cout<<"student "<<n<<" updated\n";}
        return;
    }
    bool linked_list ::deleteNode(int n){
        if(n<0) return false;
        current=head;
        for(int i=1 ; i<n ;i++)
            current=current->next;
        if(n)    
            current->next=ptrSearch->next;
        else{
            current=ptrSearch->next;
            head=current;
        }    
        if(ptrSearch->next==NULL)
            tail=current;
        delete ptrSearch;
        return true;    
    }
    linked_list::~linked_list(){ //! delete each node in the list
    current = head;
    while(current){
        link p = current;
        current = current->next;
        delete p;
    }
}
    
    
    // ! /* *******************************************************function to get max and avg GPA************************************************** */    
    void gpa_max_avg(float &max, linked_list l1 ,float & avg_gpa){
        int x,y,w,flag,no=0;
        float gpa=0.0,sum=0.0;
        string name="hello";
        flag=l1.first(x,y,gpa,name);
        max=gpa;
        while (flag){
        no++;
        sum+=gpa;
        if(gpa>max)
            max=gpa;
        flag=l1.next(x,y,gpa,name);       
        }
        avg_gpa=sum/no;
    }


    // ! /* ************************************************************Main function************************************************** */

int main(){
        int casess=0,old_idd=0,n,n1;
        linked_list l1;
        elemtype id_std,age_std;
        float gpa_std,max_gpa=0,gpa_avg=0;
        string name_std;
        
        cout<<"**program start**\n";
        cout<<" for add student : 1 \n display student : 2\n search for student : 3\n update student : 4\n delete student : 5\n Calculate AVG GPA : 6\n for highest GPA : 7\n EXIT! : 8\n";
        while (casess!=8){
        cout<<"enter case number from 1-7 and 8 to EXIT! \n";
        cin>>casess;
        switch (casess){
        case 1:  // ? add student ..
            cout<<"Student name : "<<"Student Id : "<<"Student GPA : "<<"Student Age : \n";
            cin.ignore();
            getline(cin,name_std);
            cin>>id_std>>gpa_std>>age_std;
            l1.insert(id_std,age_std,gpa_std,name_std);
            break;
        case 2:  // ? display all students ..
            l1.displayAll();
            break;
        case 3:  // ? search for student and print his data ..
            cout<<"enter id to search\n";
            cin>>old_idd;
             n=l1.search(old_idd,age_std,gpa_std,name_std);
            if(n>-1)
            cout<<"Student name : "<<name_std<<"\nStudent Id : "<<old_idd<<"\nStudent GPA : "<<gpa_std<<"\nStudent Age : "<<age_std<<endl;
            break;
        
        case 4:{  // ? update student by search id ..
            cout<<"enter id to search\n";
            cin>>old_idd;
            cout<<"enter new data of this student\n";
            cout<<"Student name : "<<"Student Id : "<<"Student GPA : "<<"Student Age : \n";
            cin.ignore();
            getline(cin,name_std);
            cin>>id_std>>gpa_std>>age_std;
            l1.update(old_idd,id_std,age_std,gpa_std,name_std);} // ! don't forget to ask about sending data by value
            break;
        case 5:{  // ? delete student node by id ..
            cout<<"enter id to search and delete his node \n";
            cin>>old_idd;
            string z;float y;int x;
             n1=l1.search(old_idd, x ,  y,  z );
            if (l1.deleteNode(n1))
                cout<<"node "<<n1<<"deleted\n";}
            break;
        case 6:{  // ? calc avg gpa all students ..
            gpa_max_avg(max_gpa,l1,gpa_avg);
            cout<<"AVG FOR ALL STUDENTS\n"<<gpa_avg<<endl;}
            break;
        case 7:{  // ? calc max gpa from all students ..
            gpa_max_avg(max_gpa,l1,gpa_avg);
            cout<<"MAX GPA FROM ALL STUDENTS\n"<<max_gpa<<endl;}
            break;
        default:{
            if(casess==8) break;
            cout<<"TRY AGAIN \n";
            cout<<"enter case number from 1-7 and 8 to EXIT! \n";}
            break;
            }
        }
    return 0;
}