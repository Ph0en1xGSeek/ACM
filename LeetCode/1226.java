class DiningPhilosophers {

    private ReentrantLock[] forks = new ReentrantLock[5];

    public DiningPhilosophers() {
        for(int i = 0; i < 5; ++i) {
            forks[i] = new ReentrantLock();
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        int fork1 = philosopher;
        int fork2 = (philosopher + 1) % 5;
        
        forks[Math.min(fork1, fork2)].lock();
        forks[Math.max(fork1, fork2)].lock();
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        forks[fork1].unlock();
        forks[fork2].unlock();
    }
}