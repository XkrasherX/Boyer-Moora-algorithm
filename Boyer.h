#pragma once
#include <string>
#include <vector>

const char MY_CHAR = '?';




class Boyer_Moore {

public:
    struct StopInfo {
        char stop_sign;     //стоп-символ
        int textPos;     //позиція в тексті (shift + j)
        int patternPos;  //позиція у слові (j)
        int shift;       //на скільки зсунули слово
    };

private:
    std::string text;
    std::string pattern;
    std::vector<StopInfo> stops;

    //чи збігається символ тексту 'c' з позицією 'i' шаблону
    bool matchAt(int i, char c) { return pattern[i] == MY_CHAR || pattern[i] == c; }

    //найправіша позиція в слові
    int lastOccurrence(char c)
    {
        for (int i = (int)pattern.size() - 1; i >= 0; i--) { if (matchAt(i, c)) return i; }
        
        return -1;
    }

    //зсув за стоп-символом x, що зустрівся на позиції j у слові.
    int shiftByStopSymbol(char x, int j)
    {
        int k = lastOccurrence(x);

        //k= m, якщо неспівпадіння на останньому символі
        if (k == -1) return j + 1;
        
        //k < j -> зсув на j - k
        if (k < j) return j - k;
        
        //k > j -> зсув на 1
        return 1;
    }

public:
    

    bool createObject(std::string& text, std::string& pattern) {
        if (text.empty() || pattern.empty()) return false;
        this->text = text;
        this->pattern = pattern;
        return true;
    }

    //геттери
    std::string getText() const { return text; }
    std::string getPattern() const { return pattern; }
    //std::string getSequence(int index) const { return text.substr(index, pattern.size()); }
    std::vector<StopInfo> getStops() const { return stops; }


    std::vector<int> search()
    {
        stops.clear();
        std::vector<int> matches; //індекcи збігів
        int m = pattern.size(); //розмір слова
        int n = text.size(); //розмір тексту

        if (m == 0 || m > n)
            return matches;

        int shift = 0; //зміщення слова

        //поки зміщення менше за текс-слово
        while (shift <= n - m)
        {
            int j = m - 1; //порівняння з кінця слова
            while (j >= 0 && matchAt(j, text[shift + j])) j--;

            //повний збіг
            if (j < 0) {
                matches.push_back(shift);
                if (shift + m >= n) break;

                int k = lastOccurrence(text[shift + m]); // символ тексту одразу за словом теж розглядаємо як стоп-символ
                shift += m - k; // k = -1 -> m + 1, інакше >= 1
            }
            //неспівпадіння на символі text[shift + j]
            else {
                int d = shiftByStopSymbol(text[shift + j], j);
                stops.push_back({ text[shift + j],shift + j,j, d});
                shift += d;
            }
        }
        return matches;
    }
};
