#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<time.h>

/*There are 5 players, each judge give one score, then delete the highest and lowest 
score, calculate the average scores.
*/
class Person {
public:
	Person(string name, int score) {
		this->m_NAme = name;
		this->m_Score = score;
	}

	string m_NAme;
	int m_Score;
};

void creatPerson(vector<Person>& v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "player";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		v.push_back(p);
	}
}

void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//put score into deque
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60; //60~100
			d.push_back(score);
		}

		cout << "player: " << it->m_NAme << " score: " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			cout << *dit << " ";
		}
		cout << endl;
		//sort
		sort(d.begin(), d.end());
		//delete the highest and lowest score
		d.pop_back();
		d.pop_front();

		//get the average
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit ++) {
			sum += *dit;
		}
		int average = sum / d.size();

		it->m_Score = average;

	}
}

void showScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it ++) {
		cout << "Player: " << it->m_NAme << " Score: " << it->m_Score << endl;
	}
}

int main() {
	//Random seed
	srand((unsigned int)time(NULL));

	//1. creat 5 player
	vector<Person>v;
	creatPerson(v);

	//test
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << "name: " << (*it).m_NAme << " score: " << (*it).m_Score << endl;
	//}

	//2. give scores to player
	setScore(v);

	//3. show the final score
	showScore(v);

	system("pause");

	return 0;
}