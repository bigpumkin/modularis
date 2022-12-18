#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>

using namespace std;

void seq_shift(vector<int> seq, size_t shift)
{
	for (int j = 0; j != shift; j++)
	{
		int buf = seq[0];
		
		for(int i=0; i < seq.size() - 1; i++)
		{
		    seq[i] = seq[i + 1];
	    	seq[seq.size() - 1] = buf;
		}
	}
}

void seq_random(vector<int>seq, size_t percent)
{
	
	int num_rand = seq.size() * percent / 100;
	srand(time(NULL));
    
	for (int i=0; i < num_rand; i++)
	{		
		int index_rand = rand() % seq.size();
		seq[index_rand] = 1 + rand() %2;
		if (seq[index_rand] != 0)	
		{
			seq[index_rand] -= 1;
		}	
	}
}

vector<int> eu_gen(size_t length_seq, size_t num_beat)
{
    	vector<int> seq;

    	for (int i = 0; i != length_seq; i++)
    	{
    		int multiplied = length_seq * i;
	    	int index;
    		index = multiplied / num_beat + (multiplied % num_beat ? 1 : 0);
            
            if (index < length_seq)
            {
	        	seq[index] = 1;
            }
            else {break;}
            
    	}
        return seq;
	
}

void seq_xor(vector<int>  seq, size_t, size_t shift)
{
    vector<int> seq2;
    size_t length_seq = seq.size();
    
    srand(time(NULL));   
    for (int i = 0; i < length_seq; i++)
    {
    	seq2[i] = seq[i];
    }
    
    seq_shift(seq2, shift);
    
    for (int i = 0; i < length_seq; i++)
    {
    	seq[i] ^= seq2[i];
    }
}
