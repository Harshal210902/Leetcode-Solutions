//TC = O(n^2)
//SC = O(n^2)
int minAreaRect(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, unordered_set<int>> hashmap;
        
        for(auto& single_point: points) 
            hashmap[single_point[0]].insert(single_point[1]); 
        int minimum_area = INT_MAX; 
        
        for(int i = 0; i < points.size(); i++) { 
            for(int j = i + 1; j < points.size(); j++) { 
			
                int x1 = points[i][0], y1 = points[i][1];  
				int x2 = points[j][0], y2 = points[j][1];  
                
                if(x1 != x2 && y1 != y2) 
                    if( hashmap[x1].find(y2) != hashmap[x1].end() 
											&& 
					hashmap[x2].find(y1) != hashmap[x2].end() ) 
					
                        minimum_area = min( minimum_area , abs(x1-x2) * abs(y1-y2) ); 
            }
        }
        hashmap.clear();
        return minimum_area != INT_MAX ? minimum_area : 0; 
    }
