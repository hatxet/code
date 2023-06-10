#include <cstdio>
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

struct turtle{
	int capacity;
	int strength;
};

std::ostream& operator<<(std::ostream& out, const turtle& t){
	out << "(" << t.strength-t.capacity << "/" << t.strength << ")";
	return out;
}

bool turtle_comp(const turtle& a, const turtle& b) {
	if ((a.capacity > b.capacity) || (a.capacity == b.capacity && a.strength < b.strength))
		return true;
	return false;
}

int	sack(std::vector<turtle> turtles, int capacity){
	int num = 0;
	for (int i = 0; i < turtles.size(); ++i){
		if (turtles.front().strength <= capacity){
			std::cout << "Cap: " << capacity << " on i: " << i << std::endl;
			++num;
			capacity = turtles.front().capacity;
		} else if ((turtles.front().strength-turtles.front().capacity) <= capacity){
			std::cout << "Cap: " << capacity << " on i: " << i << std::endl;
			++num;
			break;
		}
	}
	return num;
}
int main(){
	int capacity, weight, strength, num = 0;
	std::vector<turtle> turtles;

	while(scanf("%d %d", &weight, &strength) != EOF){
		turtle t = {strength-weight, strength};	
		turtles.push_back(t);
	}
	std::sort(turtles.begin(), turtles.end(), turtle_comp);	
	for(int i = 0; i < turtles.size(); ++i) std::cout << turtles[i] << " ";
	std::cout << sack(turtles, std::numeric_limits<int>::max());
	std::cout << std::endl;
}
