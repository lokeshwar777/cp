#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

struct Employee {
    int employee_id;
    string employee_name;
    double employee_salary;
};

void display_employee_details(const Employee& employee) { // just use the reference and do not modify it
    cout << "Employee ID : " << employee.employee_id << ", ";
    cout << "Employee Name : " << employee.employee_name << ", ";
    cout << "Employee Salary : " << employee.employee_salary << " Rupees" << endl;
}

int main() {
    vector<Employee> employees = {
        {1, "Thor", 10000},
        {2, "Loki", 20000},
        {3, "Odin", 70000},
        {4, "Deadpool", 45000},
        {5, "Wolverine", 49000},
        {6, "QuickSilver", 28000},
    };

    sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2 ){
        return e1.employee_salary <  e2.employee_salary;
    }); // requires iterators, lambda

    cout << "After sorting :" << endl;
    for_each(employees.begin(), employees.end(), display_employee_details);

    vector<Employee> well_paid_employees;

    copy_if(employees.begin(), employees.end(), back_inserter(well_paid_employees),[](const Employee& e){
        return e.employee_salary > 30000;
    });

    cout << "\nHere's the details of well paid employees" << endl;
    for_each(well_paid_employees.begin(), well_paid_employees.end(), display_employee_details);


    double total_salary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee& e){ 
        return sum+e.employee_salary;
        });
    cout << "\nTotal salary paid for all employees is : " << total_salary;

    return 0;
}