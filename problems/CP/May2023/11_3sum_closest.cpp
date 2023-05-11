#include <iostream>
#include <vector>

using namespace std;

int threeSumClosest(vector<int> &nums, int target) {

    sort(nums.begin(), nums.end());
    int closest_sum = nums[0] + nums[1] + nums[2];
    int closest = abs(closest_sum - target);
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {

            int k = nums.size() - 1;
            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if (diff < closest) {
                    closest = diff;
                    closest_sum = sum;
                }
                while (j < k && nums[j + 1] == nums[j]) j++;
                while (k > j && nums[k - 1] == nums[k]) k--;
                k--;
            }
        }
    }
    return closest_sum;
}


int main() {

    vector<int> v = {-337, 159, -145, 903, -901, -395, -409, 92, -344, -468, -231, -222, -693, -902, -162, -205, 346,
                     941, -108, -695, 37, 484, 241, -645, -227, 405, 388, -98, -343, -82, 86, -19, 512, 717, 825, 599,
                     -770, 214, -411, 433, 149, 657, -361, 145, -813, -239, 161, 550, -627, 360, -873, 230, 540, -282,
                     983, 856, -327, 449, 236, 365, 165, 673, 63, -365, 683, 105, 465, 32, -779, -252, -707, -412, 40,
                     -94, 676, 26, 231, -877, -837, -974, 44, 975, -818, 463, 965, -836, 432, -844, 936, 25, 239, -490,
                     -550, 415, 323, 756, -441, -835, 19, 178, -403, -387, -144, -508, -152, 438, 28, -601, 755, -369,
                     895, -851, 396, -534, -351, -768, 625, 510, 566, 435, 977, 781, -894, 659, -927, 610, 313, 103,
                     -990, -668, -780, 642, -376, -771, 549, 593, -264, -58, 474, -163, -371, 33, -85, -577, 56, -822,
                     617, -283, 992, -419, 48, 500, 572, 633, -690, -259, 122, 833, -881, -533, -937, 726, 604, -671,
                     -275, 110, 665, -654, -469, -7, -456, 798, 639, -792, -708, -329, 318, -521, 976, 79, -27, -470,
                     797, 914, 650, 413, 867, 222, 21, -54, -103, 223, 428, -910, -154, -32, -687, -45, -235, 892, -977,
                     569, 621, -9, -713, -806, 927, 638, -963, 400, 519, 368, 123, -805, 107, -841, -334, 876, 448, 91,
                     -891, 254, -784, -106, 776, 754, 614, -347, -976, -526, -238, -482, 276, -262, -559, 688, 561, 920,
                     -313, -436, -759, -711, -672, 154, -744, 701, -184, -179, -497, 966, -890, 874, -39, -680, -406,
                     134, -310, -794, 352, -422, 739, 460, 227, -167, 322, 136, 901, -380, 273, 724, 846, -706, 525,
                     603, 175, 53, 507, 543, -569, -544, -727, -307, 518, -339, -208, -191, -25, -78, -651, -204, 822,
                     -802, -159, -33, 359, 957, -166, -298, 430, 715, 164, 692, 587, 637, 472, 426, -224, -60, 889, 321,
                     31, -207, -453, -956, 714, -545, -288, 424, -736, 288, -872, -984, 167, 761, -757, -86, -285, -996,
                     -847, -64, 156, -785, -218, -442, 933, 126, 445, -915, 766, -524, 959, -720, 410, 909, -216, -156,
                     -228, -629, -434, -173, 8, 790, 799, 919, -817, -900, -230, -270, -358, -621, 647, 240, -111, -663,
                     225, 183, -833, 864, -26, 480, 849, -291, 940, -437, -763, -367, 998, 118, 459, -895, -639, -630,
                     -917, -140, -558, 174, -488, 188};
    cout << threeSumClosest(v, 4030);
}

// https://leetcode.com/problems/3sum-closest/
// medium