#include <iostream> 

#include <vector> 

#include <string> 

#include <cmath> 

#include <iomanip> 

#include <algorithm> 

#include <fstream> 

  

using namespace std; 

  

struct program 

{ 

  string name, lastname; 

  vector<float> Assignment ; 

  float Examination, Terminal_Score, Terminal_Score_median; 

}; 

  

float Terminal_Score_average_function ( vector<float> Assignment _data, float Examination_function ) 

{ 

    float sum; 

    for(int k=0; k<=Assignment _data.size(); k++) 

    { 

        sum += Assignment _data[k]; 

    } 

    float r; 

    r = sum / Assignment _data.size() * 0.4 + Examination_function * 0.6; 

    return r; 

} 

  

float Terminal_Score_median_function (vector<float> Assignment _data_2, float Examination_function_2) 

{ 

    float median_Score_short_term; 

        sort(Assignment _data_2.begin(), Assignment _data_2.end()); 

        if (Assignment _data_2.size() % 2 == 0) 

            median_Score_short_term = (Assignment _data_2[Assignment _data_2.size()/2 - 1] + Assignment _data_2[Assignment _data_2.size()/2]) / 2; 

  

        else 

            median_Score_short_term = Assignment _data_2[Assignment _data_2.size()/2]; 

    float r_2; 

    r_2 = median_Score_short_term *0.4 + 0.6 * Examination_function_2; 

    return r_2; 

} 

  

int main() 

{ 

    float grade; 

    vector<program> pupil; 

    int i; 

    char decision_2; 

    cout << "Want to read the text file? y/n\n"; 

    cin >> decision_2; 

    switch (decision_2) 

    { 

    case 'y': 

        {string line; 

        int f=0; 

        ifstream myfile("book.txt"); 

        if (myfile.is_open()) 

        { 

            cout << left << setw(30) << "Name" << setw(30) << "Lastname" << right << setw(28) << "Terminal grade (Avg.)" << left << setw(28) << "/ Terminal grade (Med.)" << endl; 

            cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

            int a,b,c,d,e,f_Examination; 

            string name_text,lastname_text; 

            while (getline(myfile,line)) 

                { 

            if (myfile >> name_text >> lastname_text >> a >> b >> c >> d >> e >> f_Examination) 

            { 

                pupil.push_back(program()); 

                pupil[f].name = name_text; 

                pupil[f].lastname = lastname_text; 

                pupil[f].Assignment .push_back(a); 

                pupil[f].Assignment .push_back(b); 

                pupil[f].Assignment .push_back(c); 

                pupil[f].Assignment .push_back(d); 

                pupil[f].Assignment .push_back(e); 

                pupil[f].Examination = f_Examination; 

                pupil[f].Terminal_Score = Terminal_Score_average_function(pupil[f].Assignment , pupil[f].Examination); 

                pupil[f].Terminal_Score_median = Terminal_Score_median_function(pupil[f].Assignment , pupil[f].Examination); 

                cout  << left << setw(30) << pupil[f].name << setw(30) << pupil[f].lastname 

        << right << setw(28) << setprecision(2) << fixed << pupil[f].Terminal_Score << right << setw(30) << pupil[f].Terminal_Score_median << '\n'; 

                f++; 

  

            } 

            else 

                {cout << left << setw(30) << "Name" << setw(30) << "Lastname" << right << setw(28) << "Terminal grade (Avg.)" << left << setw(28) << "/ Terminal grade (Med.)" << endl; 

    cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl;} 

                }} 

        else {cout << "Unable to open the file";} 

  

  

  

        break;} 

        case 'n': 

    { 

        for(i=0; i<999; i++) 

    { 

        string name_short_term, lastname_short_term; 

        cout << "Please enter pupil's name: \n"; 

        cin >> name_short_term; 

        if (name_short_term == "0") break; 

  

        cout << "Enter pupil's lastname: \n"; 

        cin >> lastname_short_term; 

        if (lastname_short_term == "0") break; 

        pupil.push_back(program()); 

  

        pupil[i].name = name_short_term; 

        pupil[i].lastname = lastname_short_term; 

  

        float total_Assignment _short_term = 0; 

        int k; 

        float Examination_short_term, Terminal_Score_short_term; 

  

        cout << "Do you want to generate random numbers as grades for Assignment ? (y/n): "; 

        char decision; 

        cin >> decision; 

        switch (decision) 

        { 

            case 'n': 

                for ( k=0; k<999; k++) 

                { 

  

                    float Assignment _short_term; 

                    cout << "Enter value of Assignment " << k+1 << ":\n"; 

                    cin >> Assignment _short_term; 

                    if (!cin || Assignment _short_term == 0 || Assignment _short_term > 10) break; 

                    pupil[i].Assignment .push_back(Assignment _short_term); 

  

                } 

                cout << "Enter pupil's Score for the Examination: \n"; 

                cin >> Examination_short_term; 

                if (!cin || Examination_short_term == 0 || Examination_short_term > 10) break; 

                pupil[i].Examination = Examination_short_term; 

                pupil[i].Terminal_Score = Terminal_Score_average_function(pupil[i].Assignment , pupil[i].Examination); 

                break; 

  

  

            case 'y': 

                cout << "Enter number of Assignment s: "; 

                int number_Assignment s; 

                cin >> number_Assignment s; 

                for(int m=0; m<number_Assignment s; m++) 

                { 

                    pupil[i].Assignment .push_back(rand()%11); 

  

                } 

                pupil[i].Examination = rand()%11; 

  

            default: 

                break; 

        } 

        pupil[i].Terminal_Score_median = Terminal_Score_median_function(pupil[i].Assignment , pupil[i].Examination); 

        pupil[i].Terminal_Score = Terminal_Score_average_function(pupil[i].Assignment , pupil[i].Examination); 

  

    } 

  

    cout << left << setw(30) << "Name" << setw(30) << "Lastname" << right << setw(28) << "Terminal grade (Avg.)" << left << setw(28) << "/ Terminal grade (Med.)" << endl; 

    cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

    for (int l=0; l <=i; l++) 

    { 

        cout  << left << setw(30) << pupil[l].name << setw(30) << pupil[l].lastname 

        << right << setw(28) << setprecision(2) << fixed << pupil[l].Terminal_Score << right << setw(30) << pupil[l].Terminal_Score_median << '\n'; 

    } 

    break;} 

  

    default: 

        break; 

    } 

    return 0; 

} 