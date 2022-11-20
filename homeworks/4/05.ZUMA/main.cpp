#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Ball {
    long long int number;
    size_t colour;
    Ball(size_t _number, size_t _colour)
        : number(_number), colour(_colour) {};
};

size_t checkOptimised(list<Ball>& balls, list<Ball>::iterator position, size_t color, list<Ball>::iterator& startOfSubs, list<Ball>::iterator& endErase) {
    auto copyIter = position;
    size_t count = 1;
    startOfSubs = position;
    auto begin = balls.begin();
    auto end = balls.end();
    while (position != begin && position->colour == color) {
        position = prev(position);
        //if (position == balls.begin()) { break; }
        if (position->colour != color) { break; }
        count++;
        startOfSubs = position;
    }
    while (copyIter != end && copyIter->colour == color) {
        copyIter = next(copyIter);
        if (copyIter == balls.end()) {
            endErase = copyIter;
            break;
        }
        endErase = copyIter;
        if (copyIter->colour != color) { break; }
        count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N, Q;
    cin >> N;
    size_t currentBallColour = 0;
    list<Ball> balls;


    size_t currentSize = N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> currentBallColour;
        balls.push_back(Ball(i, currentBallColour));
    }

    


    cin >> Q;
    list<Ball>::iterator* iterators = new list<Ball>::iterator[N+Q+1]{ balls.begin() };
    size_t currentPosition = 0;
    size_t colorThrown = 0;
    vector<size_t> positions;
    vector<size_t> colorsThrown;
    for (unsigned int i = 0; i < Q; i++)
    {
        cin >> currentPosition >> colorThrown;
        positions.push_back(currentPosition);
        colorsThrown.push_back(colorThrown);
    }

    auto beginIter = balls.begin();
    auto endIter = balls.end();

    size_t counter = 0;
    for (auto i = beginIter; i != endIter; i++)
    {

        iterators[counter] = i;
        counter++;
    }

    size_t numberOfBall = balls.size();
    bool isGameOver = currentSize == 0;
    size_t currentPositionThrown = 0;
    size_t currentColorThrown = 0;
    for (size_t i = 0; i < Q; i++)
    {
        if (isGameOver) {
            cout << "Game Over" << '\n';
            continue;
        }
        currentPositionThrown = positions[i];
        currentColorThrown = colorsThrown[i];
        /*if (currentPositionThrown >= balls.size()) {
            currentPositionThrown = balls.size() - 1;
            
        }*/
        auto iter = iterators[currentPositionThrown];
        auto iterInserted = balls.begin();
        if (iter == prev(balls.end())) {
            balls.push_back(Ball(numberOfBall, currentColorThrown));
            iterInserted = prev(balls.end());
            //iterInserted = balls.end();
            
            
        }
        else if (iter == balls.begin()) {
            balls.push_front(Ball(numberOfBall, currentColorThrown));
            iterInserted = balls.begin();
            
        }
        else {
            iter++;
            iterInserted = balls.insert(iter, Ball(numberOfBall, currentColorThrown));
        }
        iterators[numberOfBall] = iterInserted;
        numberOfBall++;
        

        /*cout << "----------------" << '\n';
        auto beginIter = balls.begin();
        auto endIter = balls.end();
        for (auto i = beginIter; i != endIter; i++)
        {
            cout << i->colour << ' ';
        }
        cout << '\n';
        cout << "----------------" << '\n';*/



        size_t totalBallsRemoved = 0;
        auto startPos = balls.begin();
        auto endErase = balls.end();
        

        size_t countRemovedBalls = checkOptimised(balls, iterInserted, currentColorThrown, startPos, endErase);
        /*if (endErase == prev(balls.end())) {
            endErase++;

        }*/
       


        while (countRemovedBalls >= 3) {
            bool deleteFromEnd = endErase == balls.end();
            bool deleteFromStart = startPos == balls.begin();

            auto copyStartPos = startPos;
            if (startPos != balls.begin()) {
                copyStartPos--;
            }
            balls.erase(startPos, endErase);
            /*cout << "----------------After erase:" << '\n';
            auto beginIter = balls.begin();
            auto endIter = balls.end();
            for (auto i = beginIter; i != endIter; i++)
            {
                cout << i->colour << ' ';
            }
            cout << '\n';
            cout << "----------------" << '\n';*/
            totalBallsRemoved += countRemovedBalls;
            if (balls.size() == 0) { isGameOver = true; break; }
            if (deleteFromStart || deleteFromEnd) { break; }

            startPos = copyStartPos;

            auto testEnd = endErase;
            if (startPos->colour != testEnd->colour) { break; }
            iterInserted = startPos;
            countRemovedBalls = checkOptimised(balls, iterInserted, iterInserted->colour, startPos, endErase);
            /*if (endErase == prev(balls.end())) {
                endErase++;

            }*/
        }
        cout << totalBallsRemoved << '\n';
    }
    if (balls.size() == 0) {
        cout << "-1" << '\n';
        return 0;
    }
    auto begin = balls.begin();
    auto end = balls.end();
    for (auto i = begin; i != end; i++) {
        cout << i->colour << ' ';
    }
    delete[] iterators;

}