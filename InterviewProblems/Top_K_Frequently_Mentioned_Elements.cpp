struct compare {
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};

vector <string> topMentioned(vector <string> reviews, vector <string> keywords, int k)
{
    vector <string> result;
    unordered_map <string, int> count_map; // to store count reviews in which a keyword appears

    regex re("[^A-Za-z]"); // non-alphabetical chars

    unordered_set <string> keywords_set; 
    // using a set, to search for valid keywords later in O(1)
    // could also use unordered_map <string, bool>
    for (string s: keywords) {
        keywords_set.insert(s);
    }
    
    for (string paragraph: reviews) {        
        unordered_set <string> words; 
        // using set, since we need to count each keyword only once in a review

        string clean = regex_replace(paragraph, re, " "); // replacing non alphabetical chars with space

        stringstream ss(clean);
        string token;
        while (ss >> token){ // splitting by space
            words.insert(token);
        }

        for (string word: words) { // increasing count for each keyword in the paragraph
            if (keywords_set.find(word) != keywords_set.end()) // searches in constant time
                count_map[word] += 1;
        }
    }
    

    priority_queue < pair<string, int>, vector < pair<string, int> >, compare > pq (count_map.begin(), count_map.end());
    
    while (k--) {
        string p = pq.top().first; pq.pop();        
        result.push_back(p); 
    }
    
    return result;
}