#include <iostream> 

#include <vector> 

#include <string> 

#include <cmath> 

#include <iomanip> 

#include <algorithm> 

  

using namespace std; 

  

struct program 

{ 

  string name, lastname; 

  vector<float> Assignment ; 

  float Examination, Terminal_Score, Terminal_Score_median; 

}; 

  

int main() 

{ 

    float grade; 

    vector<program> pupil; 

    int i; 

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

                    total_Assignment _short_term += Assignment _short_term; 

  

                } 

  

                if (total_Assignment _short_term == 0) break; 

                cout << "Enter pupil's Score for the Examination: \n"; 

                cin >> Examination_short_term; 

                if (!cin || Examination_short_term == 0 || Examination_short_term > 10) break; 

                pupil[i].Examination = Examination_short_term; 

                Terminal_Score_short_term = 0.4 * total_Assignment _short_term /  k + 0.6 * Examination_short_term; 

                pupil[i].Terminal_Score = Terminal_Score_short_term; 

                break; 

  

  

            case 'y': 

                cout << "Enter number of Assignment s: "; 

                int number_Assignment s; 

                cin >> number_Assignment s; 

                for(int m=0; m<number_Assignment s; m++) 

                { 

                    pupil[i].Assignment .push_back(rand()%11); 

                    total_Assignment _short_term += pupil[i].Assignment [m]; 

  

                } 

                Examination_short_term = rand()%11; 

                Terminal_Score_short_term = 0.4 * total_Assignment _short_term /  pupil[i].Assignment .size() + 0.6 * Examination_short_term; 

                pupil[i].Terminal_Score = Terminal_Score_short_term; 

  

            default: 

                break; 

        } 

  

        float median_Score_short_term; 

        sort(pupil[i].Assignment .begin(), pupil[i].Assignment .end()); 

        if (pupil[i].Assignment .size() % 2 == 0) 

            median_Score_short_term = (pupil[i].Assignment [pupil[i].Assignment .size()/2 - 1] + pupil[i].Assignment [pupil[i].Assignment .size()/2]) / 2; 

  

        else 

            median_Score_short_term = pupil[i].Assignment [pupil[i].Assignment .size()/2]; 

  

        float median_Terminal_Score_short_term = median_Score_short_term * 0.4 + 0.6 * Examination_short_term; 

        pupil[i].Terminal_Score_median = median_Terminal_Score_short_term; 

  

  

    } 

  

    cout << left << setw(30) << "Name" << setw(30) << "Lastname" << right << setw(28) << "Terminal grade (Avg.)" << left << setw(28) << "/ Terminal grade (Med.)" << endl; 

    cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

    for (int l=0; l <=i; l++) 

    { 

        cout  << left << setw(30) << pupil[l].name << setw(30) << pupil[l].lastname << right << setw(28) << setprecision(2) << fixed << pupil[l].Terminal_Score << right << setw(30) << pupil[l].Terminal_Score_median << '\n'; 

    } 

    return 0; 

} 

 

 