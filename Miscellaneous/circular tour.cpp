class petrolPump
{
    public:
    int petrol;
    int distance;
};

int printTour(petrolPump arr[], int n)
{
    // Consider first petrol pump as a starting point
    int start = 0;
    int end = 1;
 
    int curr_petrol = arr[start].petrol - arr[start].distance;

    while (end != start || curr_petrol < 0)
    {

        while (curr_petrol < 0 && start != end)
        {
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;
 
            // If 0 is being considered as start again, then there is no
            // possible solution
            if (start == 0)
            return -1;
        }
 
        // Add a petrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance;
 
        end = (end + 1) % n;
    }
 
    // Return starting point
    return start;
}