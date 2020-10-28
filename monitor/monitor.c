// Variables per monitor
semaphore mutex = 1;

int urgentCount = 0;
semaphore urgent = 0;

// Variables per condition
int condCount = 0;
semaphore condSem = 0;

void genericPublicFunction()
{
    // Every public function on a monitor is guarded by a mutex
    P(mutex);

    // User's code in here

    // If signalCondition() is called, and execution is passed to
    // a waiting process, then we must pass execution back to the
    // signaling process immediately.
    if (urgentCount > 0)
        V(urgent);
    else
        V(mutex);
}

void waitOnCondition()
{
    condCount++;

    // Release the mutex before waiting. This is accomplished either by
    // releasing the mutex, or passing control back to a process that already
    // held the mutex before.
    if (urgentCount > 0)
        V(urgent);
    else
        V(mutex);

    // This will always wait
    P(condSem);

    condCount--;
}

void signalCondition()
{
    urgentCount++;

    // If there are any waiting processes then the first of those processes
    // MUST be run immediately. We wait on "urgent" so that as soon as that process
    // waits again or exits the critical section, the signaling process
    // will be started again.
    if (condCount > 0) {
        V(condSem);
        P(urgent);
    }

    urgentCount--;
}
