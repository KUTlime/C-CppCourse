#include <algorithm>
#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "UnitTest.h"


int main()
{
    auto createNewQueue = []() {return PriorityQueue(); };
    std::vector<PriorityQueueUnitTest*> unitTests = {
        new PriorityQueueUnitTest
        (
            "Queue Should Enqueu The Command",
            createNewQueue,
            [](PriorityQueue queue)
            {
                ICommand someCommand;
                queue.enqueu(someCommand);
                return queue; 
            },
            [](PriorityQueue queue)
            {
                return queue.getNumberCommandsInQueue() == 1;
            }
        ),
        new PriorityQueueUnitTest
        (
            "Queue Should Enqueu Two Commands",
            createNewQueue,
            [](PriorityQueue queue)
            {
                ICommand someCommand;
                queue.enqueu(someCommand);
                queue.enqueu(someCommand);
                return queue;
            },
            [](PriorityQueue queue)
            {
                return queue.getNumberCommandsInQueue() == 2;
            }
        ),
        new PriorityQueueUnitTest
        (
            "Queue Should Enqueu into low priority queue",
            createNewQueue,
            [](PriorityQueue queue)
            {
                LowPriorityCommand someCommand;
                queue.enqueu(someCommand);
                return queue;
            },
            [](PriorityQueue queue)
            {
                return 
                    queue.getNumberCommandsInQueue() == 1;
            }
        ),
        new PriorityQueueUnitTest
        (
            "Queue should enque a command with a priority and return the same command",
            createNewQueue,
            [](PriorityQueue queue)
            {
                ICommand command("Test", 10);
                queue.enqueu(command);
                return queue;
            },
            [](PriorityQueue queue)
            {
                auto command = queue.dequeu();
                return
                    command.getPayload() == "Test"
                    &&
                    command.getPriority() == 10
                ;
            }
        )
    };
    std::ranges::for_each(unitTests, [](PriorityQueueUnitTest* ut) {ut->ExecuteTest(); });
}

