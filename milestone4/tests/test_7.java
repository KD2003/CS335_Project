class BinarySearchExample{  
     public static void binarySearch(int arr[], int first, int last, int key){  
       int mid = (first + last)/2;  
       while( first <= last ){  
          if ( arr[mid] < key ){  
            first = mid + 1;     
          }else if ( arr[mid] == key ){  
            String ans="found";
            break;  
          }else{  
             last = mid - 1;  
          }  
          mid = (first + last)/2;  
       }  
       if ( first > last ){  
        first=9999;
       }  
     }  
     public static void main(String args[]){  
            int arr[] = new int[7];  
            for(int i=0;i<7;i++){
              arr[i]=i;
            }
            int key = 30;  
            int last=7;  
            int first =0;
            binarySearch(arr,first,last,key);     
     }  
    }