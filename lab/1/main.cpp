#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/* format example:
no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
10      J.Jon   5       4       3       4
        average 3.8     3.4     3.6
        min     2       2       1
        max     5       5       5
*/

int main(){
    int* score1 = new int[10];
    int* score2 = new int[10];
    int* score3 = new int[10];
    vector<string> name (10);

    for (int i = 0; i < 10; i++){
        cin >> name[i] >> score1[i] >> score2[i] >> score3[i];
    }

    // Get the average score for each student.
    
    auto maxlen = max_element(name.begin(), name.end(), 
        [](const string& a, const string& b) {
            return a.length() < b.length();
        });

    int len = max(static_cast<int>(maxlen->length()),7);

    // The output section. 
    cout << "no" << string(6,' ')
        << "name" << string((len - 3),' ') 
        << "score1" << string(2,' ') 
        << "score2" << string(2,' ') 
        << "score3" << string(2,' ') 
        << "average" << endl; 

    // Generate the report for each student.
    for (int i = 0; i < 10; i++){
        auto sum = score1[i] + score2[i] + score3[i];
        auto avg = (sum % 3 == 0) ? 
                    (sum / 3) : 
                    ( sum / 3.00000);
        cout << i+1 << string(8 - to_string(i + 1).length(), ' ') 
            << name[i] << string(1 + len - name[i].length(), ' ') 
            << score1[i] << string(8 - to_string(score1[i]).length(), ' ') 
            << score2[i] << string(8 - to_string(score2[i]).length(), ' ') 
            << score3[i] << string(8 - to_string(score3[i]).length(), ' ') 
            << avg << endl;
    }
    int sum1 = 0, sum2 = 0, sum3 = 0;
    auto min_1 = min_element(score1, score1 + 10);
    auto min_2 = min_element(score2, score2 + 10);
    auto min_3 = min_element(score3, score3 + 10);
    auto max_1 = max_element(score1, score1 + 10);
    auto max_2 = max_element(score2, score2 + 10);
    auto max_3 = max_element(score3, score3 + 10);
    for (int i = 0; i < 10; i++){
        sum1 += score1[i];
        sum2 += score2[i];
        sum3 += score3[i];
    }
    float avg1 = sum1 / 10.0;
    float avg2 = sum2 / 10.0;
    float avg3 = sum3 / 10.0;

    // Output the summary statistics.
    cout <<  string(8,' ') << "average" << string((len-6),' ') 
                        << avg1 << string(13 - to_string(static_cast<float>(avg1)).length(),' ')
                        << avg2 << string(13 - to_string(static_cast<float>(avg2)).length(),' ')
                        << avg3 << endl;
    cout <<  string(8,' ') << "min" << string((len-2),' ') 
                        << *min_1 << string(8 - to_string(static_cast<int>(*min_1)).length(),' ') 
                        << *min_2 << string(8 - to_string(static_cast<int>(*min_2)).length(),' ') 
                        << *min_3 << endl;
    cout <<  string(8,' ') << "max" <<  string((len-2),' ') 
                        << *max_1 << string(8 - to_string(static_cast<int>(*max_1)).length(),' ') 
                        << *max_2 << string(8 - to_string(static_cast<int>(*max_2)).length(),' ') 
                        << *max_3 << endl;
    return 0;
}