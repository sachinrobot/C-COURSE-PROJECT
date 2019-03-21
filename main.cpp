#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>n;
     ;
    vector<string>name;
    vector<string>surname;
    vector<int>result;
    vector<float>avgfinalpoints;
    vector<float>medfinalpoints;
    string temp;
    int temp1;
    int flag=1;
    char opt,ch;
    float median;
    for(int i=0;flag==1;i++)
    {
        int temp2=0,flag1=1;
        cout<<"Enter the name";
        cin>>temp;
        name.push_back(temp);
        cout<<"\n Enter the surname";
        cin>>temp;
        surname.push_back(temp);
        for(int j=1;flag1==1;j++)
        {
            cout<<"\n Enter the results of the homework";
            cin>>temp1;
            n.push_back(temp1);
            cout<<"Would you like to enter more (y/n)?";
            cin>>opt;
            if(opt=='y')
                flag1=1;
            else if(opt=='n')
                flag1=0;
            else
            {
                cout<<"invalid choice!!!";
                flag1=0;
            }
        }
        cout<<"Enter the results of the Exam";
        cin>>temp1;
        result.push_back(temp1);
        cout<<"Would you like to enroll more students (y/n)?";
        cin>>opt;
        if(opt=='y')
            flag=1;
        else if(opt=='n')
            flag=0;
        else
        {
            cout<<"invalid choice!!!";
            flag=0;
        }
        for(int i=0;i<n.size();i++)
        {
            temp2=temp2+n[i];
        }
        temp2=((temp2)/n.size());
        avgfinalpoints.push_back(((0.4*temp2)+(0.6*result[i])));
        for(int i=0;i<n.size();i++) //Sorting
        {
            for(int j=0;j<n.size()-i;j++)
            { if(n[j]>n[j+1])
            {
                int tempor=n[i];
                n[j]=n[j+1];
                n[j+1]=tempor;
            }
            }
        }
        if ((n.size())% 2 != 0)
            median= (double)n[(n.size())/2];
        else
            median= (double)(n[(n.size()-1)/2] + n[n.size()/2])/2.0;
        
        medfinalpoints.push_back(((0.4*median)+(0.6*result[i])));
        
    }
    cout<<"\n how would you like to Output 1. for average 2. for median";
    cin>>ch;
    cout<<"Surname"<<"\t"<<"Name \t"<<"Finalpoints";
    if (ch=='1')
    {
        for(int i=0;i<avgfinalpoints.size();i++)
            cout<<"\n"<<surname[i]<<"\t"<<name[i]<<"\t"<<avgfinalpoints[i]<<"\n";
    }
    else if(ch=='2')
    {
        for(int i=0;i<medfinalpoints.size();i++)
            cout<<surname[i]<<"\t"<<name[i]<<"\t"<<medfinalpoints[i]<<"\n";
    }
    
}
