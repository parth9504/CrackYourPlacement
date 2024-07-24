void radix(vector<int>& v, int exp) {
    // Use counting sort
    int i;
    vector<int> freq(10, 0);
    vector<int> temp(v.size(), 0);

    // Count occurrences of each digit
    for (i = 0; i < v.size(); i++) {
        freq[(v[i] / exp) % 10]++;
    }

    // Compute cumulative frequency
    int cum = freq[0];
    for (i = 1; i < 10; i++) {
        cum += freq[i];
        freq[i] = cum;
    }

    // Place elements into temporary array
    for (i = v.size() - 1; i >= 0; i--) {
        if (freq[(v[i] / exp) % 10] >= 1) {
            freq[(v[i] / exp) % 10]--;
            temp[freq[(v[i] / exp) % 10]] = v[i];
        }
    }

    // Copy back to original array
    for (i = 0; i < temp.size(); i++) {
        v[i] = temp[i];
    }
}

void radixSort(int arr[], int n) {
    vector<int> v;
    int i;

    // Convert array to vector
    for (i = 0; i < n; i++) {
        v.push_back(arr[i]);
    }

    // Find the largest number in the array
    int max = *max_element(v.begin(), v.end());

    // Find number of digits in the largest number
    int dig = (to_string(max)).length();

    // Perform sorting for each digit
    int c = 1;
    for (int i = 1; i <= dig; i++) {
        // Call radix sort function
        radix(v, c);
        c *= 10;
    }

    // Update the original array
    for (i = 0; i < n; i++) {
        arr[i] = v[i];
    }
}
