#include <iostream>
#define MAX_CANDIDATES 5

using namespace std;

int main()
{
  int spoilt_ballots = 0;
  int ballots = 0;
  cout << "Enter the number of ballots: ";
  cin >> ballots;

  int *arr = new int[5];

  int ballot_number = 0;
  int i = 0;
  while(i < ballots)
  {
    cout << "Enter the number on ballot: ";
    cin >> ballot_number;

    if (ballot_number >= 1 && ballot_number <= 5)
    {
      arr[ballot_number-1]++;
    }
    else
    {
      spoilt_ballots++;
    }

    i++;
  }

  cout << "Result as below:" << endl;
  for(int j = 0; j < MAX_CANDIDATES; j++)
  {
    cout << "Candidate "<< j+1 <<" votes: " << arr[j] << endl;
  }

  cout << "Number of spoilts ballots: " << spoilt_ballots << endl;

  return 0;
}

