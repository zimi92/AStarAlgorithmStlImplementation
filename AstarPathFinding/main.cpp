#include "Grid.h"
#include "PathAStar.h"

int main(int argc, const char * argv[]) {
	std::pair<int, int> startPoint;
	std::pair<int, int> finishPoint;

	if (argc != 5) 
	{
		std::cout << "there is not enough arguments to run algorythm, we will use default ones" << std::endl;
		startPoint.first = 1;
		startPoint.second = 1;
		finishPoint.first = 7;
		finishPoint.second = 9;
	}
	else 
	{
		startPoint.first = static_cast<int>(*argv[1] + '0');
		startPoint.second = static_cast<int>(*argv[2] + '0');
		finishPoint.first = static_cast<int>(*argv[3] + '0');
		finishPoint.second = static_cast<int>(*argv[4] + '0');
	}
	PathAStar star;
	star.findingPath(startPoint.first, startPoint.second, finishPoint.first, finishPoint.second);
	getchar();
	return 0;
}