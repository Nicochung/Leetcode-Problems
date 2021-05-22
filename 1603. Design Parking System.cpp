class ParkingSystem {
public:
    int big_limit {}, medium_limit {}, small_limit {};
    int cur_big {}, cur_medium{}, cur_small{};
    
    ParkingSystem(int big, int medium, int small) {
        this->big_limit = big;
        this->medium_limit = medium;
        this->small_limit = small;
    }
    
    bool addCar(int carType) {
        if (isFull(carType)) {
             switch (carType) {
                case 1:
                     this->cur_big++;
                     return true;
                case 2:
                     this->cur_medium++;
                     return true;
                case 3:
                     this->cur_small++;
                     return true;
                default:
                    return false;
            }           
        }
        return false;
    }
    
    bool isFull(int carType) {
        switch (carType) {
            case 1:
                return this->cur_big < this->big_limit;
            case 2:
                return this->cur_medium < this->medium_limit;
            case 3:
                return this->cur_small < this->small_limit;
            default:
                return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
