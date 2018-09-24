#include"sequencelist.cpp"
//将一个整型SqList中的奇偶分别放在左右
void Ajust_Odd_Even(SqList<int>& obj)
{
    int temp_l, temp_r;
    int l_index = 1;
    int r_index = obj.Length();
    for(; l_index <= r_index; l_index++)
    {
        if(obj.GetElem(l_index,temp_l) % 2 == 0)
        {
            for(; r_index > l_index; r_index--)
            {
                if(obj.GetElem(r_index,temp_r) % 2 == 1)
                {
                    int change;
                    change = temp_l;
                    temp_l = temp_r;
                    temp_r = change;
                }
                else
                {
                    continue;
                }
            }
        }
        else
        {
            continue;
        }
    }
    return;
}