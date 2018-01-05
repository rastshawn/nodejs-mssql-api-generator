#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;


struct Variable {
	string name;
	string type;
	string value;
	
	void setup() {
		cout << "Name: ";
		cin >> name;
		cout << "Type: ";
		cin >> type;
		cout << "Variable: ";
		cin >> value;	
	}
	void print() {
		cout << "var " + name + "Param = new Parameter(\n";
		cout << "\t'" + name + "',\n";
		cout << "\tsql." + type + ",\n";
		cout << "\t" + value + "\n";
		cout << ");\n";		
	}
};

std::vector<Variable> variables;

int main() {
	int numVariables;
	cout << "NumVariables: ";
	cin >> numVariables;
	
	for (int i = 0; i<numVariables; i++) {
		cout << "\nVariable " << i+1 << ": \n";
		Variable v;
		v.setup();
		variables.push_back(v);
	}
	
	string storedProcedure;
	cout << "Stored Procedure Name: \n";
	cin >> storedProcedure;
	 
	cout << "\n\n\n";
	 
    std::for_each(variables.begin(), variables.end(), 
		[] (Variable &v) { v.print(); });
	
	cout << "var params = [\n";

	for (int i = 0; i<variables.size()-1; i++) {
		cout << "\t" << variables[i].name << "Param,\n";
	};
	
	for (int i = variables.size()-1; i<variables.size(); i++){
		cout << "\t" << variables[i].name << "Param\n";
	}
	cout << "];\n";
	
	cout << "execProcedure('sp" << storedProcedure << "', params, function(err, response) {\n";
	cout << "\tif(err) {\n\t\tres.send('there was an error processing the request.');\n\t";
	cout << "} else {\n\t\tres.send(response);\n\t}\n";
	
	cout << "});\n";
	
}
