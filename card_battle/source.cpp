//Dhruv Bhatti
#include <iostream>
#include <memory>
#include <math.h>
#include<iostream>
#include<vector>
#include<string>
#include <cstdlib>
#include<unordered_map>
#include<sstream>
#include <random>
#include<fstream>

using namespace std;
vector<string> cardsDeck{ "KC", "QC", "JC", "10C","9C", "8C", "7C", "6C", "5C", "4C", "3C", "2C", "AC", "KD", "QD", "JD", "10D", "9D", "8D" ,"7D" ,"6D","5D","4D","3D", "2D", "AD", "KH", "QH", "JH", "10H", "9H", "8H", "7H", "6H", "5H" ,"4H" ,"3H", "2H" ,"AH" ,"KS" ,"QS", "JS" ,"10S" ,"9S", "8S", "7S", "6S" ,"5S" ,"4S" ,"3S", "2S" ,"AS" };

class player {
public:
	vector<string> playerDeck;
};


void distribute(vector<player>& vec)
{
	int j = 0;
	while (j < 52)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (j == 52)
				break;
			vec[i].playerDeck.push_back(cardsDeck[j++]);
		}
	}
}


class comparator {
public:

	bool operator()(const std::string st1, const std::string st2) const
	{
		int x = 0;
		int y = 0;
		int ttemp1 = 0;
		for (int i = 0; i < st1.size(); i++)
		{
			if (st1[i] >= 50 && st1[i] <= 57)
			{
				ttemp1 += st1[i] - '0';
				break;
			}
			else if (st1[i] == 'J' || st1[i] == 'Q' || st1[i] == 'K')
			{
				if (st1[i] == 'J')
				{
					ttemp1 += 11;
					break;
				}
				else if (st1[i] == 'Q')
				{
					ttemp1 += 12;
					break;
				}
				else
				{
					ttemp1 += 13;
					break;
				}
			}
			else
			{
				ttemp1 += 10;
				break;
			}
		}
		int ttemp2 = 0;
		for (int i = 0; i < st2.size(); i++)
		{
			if (st2[i] >= 50 && st2[i] <= 57)
			{
				ttemp2 += st2[i] - '0';
				break;
			}
			else if (st2[i] == 'J' || st2[i] == 'Q' || st2[i] == 'K')
			{
				if (st2[i] == 'J')
				{
					ttemp2 += 11;
					break;
				}
				else if (st2[i] == 'Q')
				{
					ttemp2 += 12;
					break;
				}
				else
				{
					ttemp2 += 13;
					break;
				}
			}
			else
			{
				ttemp2 += 10;
				break;
			}
		}
		return ttemp1 < ttemp2;
	}
}comp;


void simulate(vector<player> v1, std::ofstream& file) {
	int tt = 1;
	for (auto df : v1)
	{
		file << "Hand " << tt++ << "\n";
		for (auto ass : df.playerDeck)
		{
			file << ass << " ";
		}
		file << "\n\n";
	}
}



int action(vector<player> v1, std::ofstream& file)
{
	vector<string> temp{};
	int players = v1.size();

	while (players > 1)
	{
		int x = 0;
		int y = 0;

		temp.clear();
		int tt = 1;
		for (auto df : v1)
		{
			file << "Hand " << tt++ << "\n";
			for (auto ass : df.playerDeck)
			{
				file << ass << " ";
			}
			file << "\n\n";
		}


		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].playerDeck.size() != 0)
			{
				temp.push_back(v1[i].playerDeck[0]);
				std::vector<std::string>& abc = v1[i].playerDeck;
				abc.erase(abc.begin());
			}
			else
				temp.push_back("");
		}


		vector<string> ttemp2 = temp;
		sort(ttemp2.begin(), ttemp2.end(), comp);
		string smallest{ "" };
		for (auto str : ttemp2)
		{
			if (str == "")
				continue;
			else
			{
				smallest = str;
				break;
			}
		}

		int jj = 0;
		for (auto dd : temp)
		{
			if (dd == smallest)
				break;
			jj++;

		}

		player& winner = v1[jj];

		for (auto dd : temp)
		{
			if (dd == "")
				continue;
			winner.playerDeck.push_back(dd);

		}

		tt = 1;
		for (auto df : temp)
		{
			file << "Table " << tt++ << "\n";

			file << df << " ";

			file << "\n";
		}
		file << "\n\n";
		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(winner.playerDeck.begin(), winner.playerDeck.end(), g);
		players = 0;
		for (auto obj : v1)
			if (obj.playerDeck.size() != 0)
				players++;

	}

	/*simulation(v1, file);
*/
	int winner = 1;
	for (auto d : v1) {
		for (auto ax : d.playerDeck) {
			if (d.playerDeck.empty()) {
				winner++;
			}
			else {
				break;
			}
		}
	}

	file << "Game Over!!! Winner is Player " << winner << "\n";

	simulate(v1, file);

	/*int tt = 1;
	for (auto df : v1)
	{
		file << "Hand " << tt++ << "\n";
		for (auto ass : df.playerDeck)
		{
			file << ass << " ";
		}
		file << "\n\n";
	}*/

	return 0;
}



int main() {

	int n = 0;
	std::cout << "Enter number of players  ";
	std::cin >> n;

	std::ofstream file;
	file.open("data1.txt");
	//myfile << "Writing this to a file.\n";
	file << "********************************************Initial deck of card before shuffle************************************************************\n\n";
	for (auto aa : cardsDeck)
		file << aa << " ";
	file << "\n\n";

	vector<player> playervec;
	for (int i = 0; i < n; i++)
	{
		player obj;
		playervec.push_back(obj);

	}

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(cardsDeck.begin(), cardsDeck.end(), g);
	file << "********************************************Initial deck of card after shuffle***********************************************************\n\n";
	for (auto aa : cardsDeck)
		file << aa << " ";
	file << "\n\n";

	distribute(playervec);
	// After cards are dealt to players
	int t = 1;
	for (auto& temp : playervec)
	{
		file << "Cards for player " << t++ << "\n";
		for (auto& ss : temp.playerDeck)
		{
			file << ss << " ";
		}
		file << "\n";
	}
	file << "\n";


	action(playervec, file);

	return 0;
}