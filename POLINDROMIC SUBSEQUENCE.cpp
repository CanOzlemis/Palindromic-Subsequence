
#include <iostream>
#include <vector>
#include <string>


void display(std::vector < std::vector<int> > v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) { //Printing the row of the d table
				std::cout << v[i][j] << "\t";
		}
		std::cout << "\n";
	}
}



int max(int a, int b) {
	if (a < b)
		return b;
	return a;
}

void polindromic(std::string text, std::vector < std::vector <int>  > L) {
	for (int i = 0; i < L.size(); i++) {
		for (int j = 0; j < L[i].size(); j++) {
			if (i == j)
				L[i][j] = 1;

		}
	}


	int i = 0, j = 1, counter = 2;

	while (true) {

		if (i == L.size())
			break;

		if (j == L[i].size())
		{
			if (counter == L[i].size())
				break;
			j = counter;
			counter++;
			i = 0;
		}

		if (text[i] != text[j])
			L[i][j] = max(L[i + 1][j], L[i][j - 1]);
		else if ((text[i] == text[j]) && (j == i + 1))
			L[i][j] = 2;
		else
			L[i][j] = L[i + 1][j - 1] + 2;
			

		i++;
		j++;
	}
	display(L);
	std::cout << "\tResult = " << L[0][L[0].size() - 1] << "\n\n\n";


	i = 0;
	j = L[0].size() - 1;

	std::cout << "\tPolindromic = ";
	while (true) {



		if (L[i + 1][j] == L[i][j - 1] && L[i + 1][j] > L[i][j - 1]) {
			i++;
			
		}
		else if (L[i + 1][j] < L[i][j - 1]){
			j--;
		}
		else {
			i++;
			j--;
		}
		std::cout << text[i];

		if (L[i][j] == 0)
			break;
	}
} 


int main()
{
	std::string text = "ACECC";
	std::vector < std::vector <int>  > L (text.size(), std::vector <int> (text.size()) );
	polindromic(text, L);
}

