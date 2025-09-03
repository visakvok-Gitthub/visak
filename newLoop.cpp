#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Function declarations
void patientMenu();
void appointmentMenu();
void treatmentMenu();

void CreatePatientRecord();
void SearchPatientRecord();
void UpdatePatientRecord();
void DeletePatientRecord();

void CreateAppointment();
void SearchAppointment();
void UpdateAppointment();
void DeleteAppointment();

void CreateTreatment();
void SearchTreatment();
void UpdateTreatment();
void DeleteTreatment();

int main() {
    int choice;
    cout << "Hospital Patient Record System\n";
    cout << "1. Patient Details Management\n";
    cout << "2. Appointment Schedule Management\n";
    cout << "3. Treatment History Management\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: patientMenu(); break;
        case 2: appointmentMenu(); break;
        case 3: treatmentMenu(); break;
        case 4: cout << "Exiting the program."; break;
        default: cout << "Invalid choice.\n";
    }
}

// Patient Details Management
void patientMenu() {
    int choice;
    cout << "1. Create Patient Record\n";
    cout << "2. Search Patient Record by ID\n";
    cout << "3. Update Patient Record by ID\n";
    cout << "4. Delete Patient Record by ID\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: CreatePatientRecord(); break;
        case 2: SearchPatientRecord(); break;
        case 3: UpdatePatientRecord(); break;
        case 4: DeletePatientRecord(); break;
        case 5: cout << "Exiting Patient Menu.\n"; break;
        default: cout << "Invalid choice.\n";
    }
}void CreatePatientRecord() {
    ofstream file("patients.csv");
    cout<<"How many patients do you want to add?\n";
    cout<<"Enter your number: ";
    
    int t;
    cin >> t;
    int pid;
    string name, gender, age , contact;
    cout << "Enter details for  patients: PatientID Name Age Gender Contact\n";
    while (true){
        for (int i = 0; i < t; i++) {
            cin >> pid >> name >> age >> gender >> contact;
            cin.ignore();
            getline(cin, contact);
            file << pid << "," << name << "," << age << "," << gender << "," << contact << endl;
        }
        cout << "Do you want to add more treatments? (yes/no): ";
        string choice;
        cin >> choice;
        if (choice == "no" || choice == "No" || choice == "NO")
            break;
        cout << "How many treatments do you want to add?\n";
        cin >> t;
  
}
    file.close();
}

void SearchPatientRecord() {
    ifstream file("patients.csv");
    int id, searchId, found = 0;
    cout << "Enter Patient ID to search: ";
    cin >> searchId;
    vector<string> row;
    string line, word;
    while (getline(file, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        id = stoi(row[0]);
        if (id == searchId) {
            found = 1;
            cout << "ID: " << row[0] << "\nName: " << row[1] << "\nAge: " << row[2]
                 << "\nGender: " << row[3] << "\nContact: " << row[4] << endl;
            break;
        }
    }
    if (!found) cout << "Record not found\n";
    file.close();
}

void UpdatePatientRecord() {
    ifstream fin("patients.csv");
    ofstream fout("patients_new.csv");
    int id, searchId, found = 0;
    string line, word, newName, newContact;
    vector<string> row;
    cout << "Enter Patient ID to update: ";
    cin >> searchId;
    cin.ignore();
    cout << "Enter new name: ";
    getline(cin, newName);
    cout << "Enter new contact: ";
    getline(cin, newContact);
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        id = stoi(row[0]);
        if (id == searchId) {
            found = 1;
            row[1] = newName;
            row[4] = newContact;
        }
        for (size_t i = 0; i < row.size() - 1; i++) fout << row[i] << ",";
        fout << row.back() << endl;
    }
    if (!found) cout << "Record not found\n";
    fin.close();
    fout.close();
    remove("patients.csv");
    rename("patients_new.csv", "patients.csv");
}
void DeletePatientRecord() {
    ifstream fin("patients.csv");
    ofstream fout("patients_new.csv");
    int id, searchId, found = 0;
    string line, word;
    vector<string> row;
    cout << "Enter Patient ID to delete: ";
    cin >> searchId;
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        id = stoi(row[0]);
        if (id != searchId) {
            for (size_t i = 0; i < row.size() - 1; i++) fout << row[i] << ",";
            fout << row.back() << endl;
        } else found = 1;
    }
    if (found) cout << "Record deleted\n";
    else cout << "Record not found\n";
    fin.close();
    fout.close();
    remove("patients.csv");
    rename("patients_new.csv", "patients.csv");
}

// Appointment Schedule Management
void appointmentMenu() {
    int choice;
    cout << "1. Create Appointment\n";
    cout << "2. Search Appointment by Patient ID\n";
    cout << "3. Update Appointment by Patient ID\n";
    cout << "4. Delete Appointment by Patient ID\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: CreateAppointment(); break;
        case 2: SearchAppointment(); break;
        case 3: UpdateAppointment(); break;
        case 4: DeleteAppointment(); break;
        case 5: cout << "Exiting Appointment Menu.\n"; break;
        default: cout << "Invalid choice.\n";
    }
  
}
void CreateAppointment() {
    ofstream file("appointments.csv");
    cout<<"How many appointments do you want to check?\n";
    cout<<"Enter your number: ";
    
    int n;
    cin >> n;
    int pid;
    string date, time, doctor;
    cout << "Enter details for  appointments: PatientID Date Time Doctor\n";
    while (true){
        for (int i = 0; i < n; i++) {
            cin >> pid >> date >> time >> doctor;
            file << pid << "," << date << "," << time << "," << doctor << endl;
        }
        cout << "Do you want to add more appointments? (yes/no): ";
        string choice;
        cin >> choice;
        if (choice == "no" || choice == "No" || choice == "NO")
            break;
        cout << "How many appointments do you want to add?\n";
        cin >> n;
  
}
    file.close();

}

void SearchAppointment() {
    ifstream file("appointments.csv");
    int pid, searchId, found = 0;
    cout << "Enter Patient ID to search appointment: ";
    cin >> searchId;
    vector<string> row;
    string line, word;
    while (getline(file, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        pid = stoi(row[0]);
        if (pid == searchId) {
            found = 1;
            cout << "PatientID: " << row[0] << "\nDate: " << row[1]
                 << "\nTime: " << row[2] << "\nDoctor: " << row[3] << endl;
            break;
        }
    }
    if (!found) cout << "Appointment not found\n";
    file.close();
}

void UpdateAppointment() {
    ifstream fin("appointments.csv");
    ofstream fout("appointments_new.csv");
    int pid, searchId, found = 0;
    string line, word, newDate, newTime;
    vector<string> row;
    cout << "Enter Patient ID to update appointment: ";
    cin >> searchId;
    cin.ignore();
    cout << "Enter new date: ";
    getline(cin, newDate);
    cout << "Enter new time: ";
    getline(cin, newTime);
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        pid = stoi(row[0]);
        if (pid == searchId) {
            found = 1;
            row[1] = newDate;
            row[2] = newTime;
        }
        for (size_t i = 0; i < row.size() - 1; i++) fout << row[i] << ",";
        fout << row.back() << endl;
    }
    if (!found) cout << "Appointment not found\n";
    fin.close();
    fout.close();
    remove("appointments.csv");
    rename("appointments_new.csv", "appointments.csv");
}
void DeleteAppointment() {
    ifstream fin("appointments.csv");
    ofstream fout("appointments_new.csv");
    int pid, searchId, found = 0;
    string line, word;
    vector<string> row;
    cout << "Enter Patient ID to delete appointment: ";
    cin >> searchId;
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        pid = stoi(row[0]);
        if (pid != searchId) {
            for (size_t i = 0; i < row.size() - 1; i++) fout << row[i] << ",";
            fout << row.back() << endl;
        } else found = 1;
    }
    if (found) cout << "Appointment deleted\n";
    else cout << "Appointment not found\n";
    fin.close();
    fout.close();
    remove("appointments.csv");
    rename("appointments_new.csv", "appointments.csv");
}

// Treatment History Management
void treatmentMenu() {
    int choice;
    cout << "1. Create Treatment History\n";
    cout << "2. Search Treatment by Patient ID\n";
    cout << "3. Update Treatment by Patient ID\n";
    cout << "4. Delete Treatment by Patient ID\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: CreateTreatment(); break;
        case 2: SearchTreatment(); break;
        case 3: UpdateTreatment(); break;
        case 4: DeleteTreatment(); break;
        case 5: cout << "Exiting Treatment Menu.\n"; break;
        default: cout << "Invalid choice.\n";
    }
}

void CreateTreatment() {
    ofstream file("treatments.csv");
    cout<<"How many treatments do you want to check?\n";
    cout<<"Enter your number: ";
    
    int n;
    cin >> n;
    int pid;
    string diagnosis, medication, notes;
    cout << "Enter details for  treatments: PatientID Diagnosis Medication Notes\n";
    while (true){
        for (int i = 0; i < n; i++) {
            cin >> pid >> diagnosis >> medication;
            cin.ignore();
            getline(cin, notes);
            file << pid << "," << diagnosis << "," << medication << "," << notes << endl;
        }
        cout << "Do you want to add more treatments? (yes/no): ";
        string choice;
        cin >> choice;
        if (choice == "no" || choice == "No" || choice == "NO")
            break;
        cout << "How many treatments do you want to add?\n";
        cin >> n;
  
}
    file.close();
}
void SearchTreatment(){
    ifstream file("treatments.csv");
    int pid, searchId, found = 0;
    cout << "Enter Patient ID to search treatment: ";
    cin >> searchId;
    vector<string> row;
    string line, word;
    while (getline(file, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        pid = stoi(row[0]);
        if (pid == searchId) {
            found = 1;
            cout << "PatientID: " << row[0] << "\nDiagnosis: " << row[1]
                 << "\nMedication: " << row[2] << "\nNotes: " << row[3] << endl;
            break;
        }
    }
    if (!found) cout << "Treatment not found\n";
    file.close();
}

void UpdateTreatment() {
    ifstream fin("treatments.csv");
    ofstream fout("treatments_new.csv");
    int pid, searchId, found = 0;
    string line, word, newDiagnosis, newMedication, newNotes;
    vector<string> row;
    cout << "Enter Patient ID to update treatment: ";
    cin >> searchId;
    cin.ignore();
    cout << "Enter new diagnosis: ";
    getline(cin, newDiagnosis);
    cout << "Enter new medication: ";
    getline(cin, newMedication);
    cout << "Enter new notes: ";
    getline(cin, newNotes);
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        pid = stoi(row[0]);
        if (pid == searchId) {
            found = 1;
            row[1] = newDiagnosis;
            row[2] = newMedication;
            row[3] = newNotes;
        }
        for (size_t i = 0; i < row.size() - 1; i++) fout << row[i] << ",";
        fout << row.back() << endl;
    }
    if (!found) cout << "Treatment not found\n";
    fin.close();
    fout.close();
    remove("treatments.csv");
    rename("treatments_new.csv", "treatments.csv");
}
void DeleteTreatment() {
    ifstream fin("treatments.csv");
    ofstream fout("treatments_new.csv");
    int pid, searchId, found = 0;
    string line, word;
    vector<string> row;
    cout << "Enter Patient ID to delete treatment: ";
    cin >> searchId;
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) row.push_back(word);
        pid = stoi(row[0]);
        if (pid != searchId) {
            for (size_t i = 0; i < row.size() - 1; i++) fout << row[i] << ",";
            fout << row.back() << endl;
        } else found = 1;
    }
    if (found) cout << "Treatment deleted\n";
    else cout << "Treatment not found\n";
    fin.close();
    fout.close();
    remove("treatments.csv");
    rename("treatments_new.csv", "treatments.csv");
}

