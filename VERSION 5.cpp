#include <iostream> 

#include "Functions.h" 

#include <fstream> 

#include <chrono> 

  

using namespace std; 

  

int main() 

{ 

    auto start = std::chrono::high_resolution_clock::now(); 

  

    float grade; 

    vector<program> pupil; 

    int i; 

    char decision_2; 

    cout << "Want to read the text file? y/n\n"; 

    cin >> decision_2; 

    switch (decision_2) 

    { 

    case 'y': 

    { 

        int f=0; 

        ifstream myfile("book.txt"); 

        if (myfile.is_open()) 

        { 

            int a,b,c,d,e,f_Examination; 

            string name_text,lastname_text; 

            myfile.ignore(150, '\n'); 

  

            while (myfile >> name_text >> lastname_text >> a >> b >> c >> d >> e >> f_Examination) 

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

                f++; 

            } 

        } 

        else {cout << "Unable to open the file";} 

        break; 

    } 

  

  

    case 'n': 

    { 

        for(i=0; i<999; i++) 

        { 

            string name_short_term, lastname_short_term; 

            cout << "Please enter pupil's name: \n"; 

            cin >> name_short_term; 

            pupil.push_back(program()); 

            pupil[i].name = name_short_term; 

            if (name_short_term == "0") break; 

  

            cout << "Enter pupil's lastname: \n"; 

            try 

            { 

                cin >> lastname_short_term; 

                if (lastname_short_term == "0") 

                    throw "Incorrect input!"; 

                pupil[i].lastname = lastname_short_term; 

            } 

            catch (const char* msg) 

            { 

                pupil[i].lastname = "ERROR"; 

                cout << msg << endl; 

            } 

  

  

            float total_Assignment _short_term = 0; 

            int k; 

            float Examination_short_term, Terminal_Score_short_term; 

  

            cout << "Do you want to generate random numbers as grades for Assignment ? (y/n): \n"; 

            char decision; 

            cin >> decision; 

            switch (decision) 

            { 

            case 'n': 

                for ( k=0; k>-1; k++) 

                { 

                    int input; 

                    cout << "Enter value of Assignment " << k+1 << ":\n"; 

                    cin >> input; 

                    pupil[i].Assignment .push_back(input); 

                    if (!cin || input == 0 || input > 10) break; 

                } 

  

                cout << "Enter pupil's Score for the Examination: \n"; 

                cin >> Examination_short_term; 

                if (!cin || Examination_short_term == 0 || Examination_short_term > 10) break; 

                pupil[i].Examination = Examination_short_term; 

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

                break; 

  

            default: 

                cout << "Incorrect input!"; 

                break; 

            } 

            try 

            { 

                if (pupil[i].Assignment [0]==0 || pupil[i].Examination==0) 

                    throw "The pupil can not be evaluated because:"; 

                pupil[i].Terminal_Score_median = Terminal_Score_median_function(pupil[i].Assignment , pupil[i].Examination); 

                pupil[i].Terminal_Score = Terminal_Score_average_function(pupil[i].Assignment , pupil[i].Examination); 

            } 

            catch(const char* msg) 

            { 

                cout << msg << endl; 

                cout << "  1) They does not have any evaluated Assignment ;\n  2) They did not take the Terminal Examination."<< endl; 

            } 

  

        } 

        break;} 

  

    default: 

        cout << "Incorrect input!"; 

        break; 

    } 

    try 

    { 

        if ((decision_2 != 'y' && decision_2 != 'n') || pupil[0].name == "0") 

            throw "No data to output!"; 

        vector<program> unsuccessful_vector; 

        vector<program> successful_vector; 

        ofstream unsuccessful, successful; 

        for (int i=0; i<pupil.size(); i++) 

        { 

            if(pupil[i].Terminal_Score<5) 

            { 

                unsuccessful_vector.push_back(pupil[i]); 

            } 

        else 

            successful_vector.push_back(pupil[i]); 

        } 

        pupil.clear(); 

        pupil.shrink_to_fit(); 

  

        unsuccessful.open("unsuccessful.txt"); 

        unsuccessful << left << setw(90) << " List of pupils who unsuccessful the subject"; 

        unsuccessful << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

        unsuccessful << left << setw(30) << "Name" << setw(30) << "Lastname" << right << setw(28) << "Terminal grade (Avg.)" << left << setw(28) << "/ Terminal grade (Med.)" << endl; 

        unsuccessful << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

        for (int i=0; i<unsuccessful_vector.size(); i++) 

        { 

            unsuccessful << left << setw(30) << unsuccessful_vector[i].name << setw(30) << unsuccessful_vector[i].lastname 

                << right << setw(28) << setprecision(2) << fixed << unsuccessful_vector[i].Terminal_Score << right << setw(30) << unsuccessful_vector[i].Terminal_Score_median << '\n'; 

        } 

        unsuccessful.close(); 

  

        successful.open("successful.txt"); 

        successful << left << setw(90) << " List of pupils who successful the subject"; 

        successful << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

        successful << left << setw(30) << "Name" << setw(30) << "Lastname" << right << setw(28) << "Terminal grade (Avg.)" << left << setw(28) << "/ Terminal grade (Med.)" << endl; 

        successful << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

        for (int i=0; i<successful_vector.size(); i++) 

        { 

            successful << left << setw(30) << successful_vector[i].name << setw(30) << successful_vector[i].lastname 

                << right << setw(28) << setprecision(2) << fixed << successful_vector[i].Terminal_Score << right << setw(30) << successful_vector[i].Terminal_Score_median << '\n'; 

        } 

        successful.close(); 

  

        cout << '\n' << left << setw(30) << "Name" << setw(30) << "Lastname" << right << setw(28) << "Terminal grade (Avg.)" << left << setw(28) << "/ Terminal grade (Med.)" << endl; 

        cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

        cout << setfill('*') << left << setw(90) << "List of pupils who successful the subject" << endl; 

        cout << setw(90) << "*" << setfill(' ') << endl; 

        for (int i=0; i<successful_vector.size(); i++) 

        { 

            cout << left << setw(30) << successful_vector[i].name << setw(30) << successful_vector[i].lastname 

                << right << setw(28) << setprecision(2) << fixed << successful_vector[i].Terminal_Score << right << setw(30) << successful_vector[i].Terminal_Score_median << '\n'; 

        } 

        cout << setfill('*') << setw(90) << "*" << setfill(' ') << endl; 

        cout << setfill('*') << left << setw(90) << "List of pupils who unsuccessful the subject" << endl; 

        cout << setw(90) << "*" << setfill(' ') << endl; 

        for (int i=0; i<unsuccessful_vector.size(); i++) 

        { 

            cout << left << setw(30) << unsuccessful_vector[i].name << setw(30) << unsuccessful_vector[i].lastname 

                << right << setw(28) << setprecision(2) << fixed << unsuccessful_vector[i].Terminal_Score << right << setw(30) << unsuccessful_vector[i].Terminal_Score_median << '\n'; 

        } 

  

    } 

    catch(const char* no_data) 

    { 

        cout << no_data << endl; 

    } 

    auto finish = std::chrono::high_resolution_clock::now(); 

    std::chrono::duration<double> elapsed = finish - start; 

    cout << "Elapsed time: " << elapsed.count() << " s\n"; 

    return 0; 

} 