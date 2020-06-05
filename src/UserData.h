#ifndef _USERDATA_
#define _USERDATA_

class UserData{
private:
    int current_length;
    int max_length;
    int growth_item_count;
    int poison_item_count;
    int used_gate_count;

public:
    UserData();
    UserData(int current_length, int max_length, int growth_item_count, int posion_item_count, int used_gate_count){}
    int getCurrentLength();
    void setCurrentLength(int current_length);
    int getMaxLength();
    void setMaxLength(int current_length);
    int setGrowthItemCount(int growth_item_count);
    void getGrowthItemCount();
    int setPoisonItemCount(int poison_item_count);
    void getPoisonItemCount();
    void GrowthItemIncrease();
    void PoisonItemIncrease();
    void UsedGateCountIncrease();
    void setUsedGateCount(int used_gate_count);
    int getUsedGateCount();

};

#endif