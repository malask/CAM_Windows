#include "ap_int.h"
ap_uint<18> bfstree [128] = { 1032,1036,1040,2068,2072,2076,3104,4132,4136,5164,6192,7220,7224,9276,9280,10308,10312,11340,12368,12372,13400,15452,16480,18532,20584,20588,21616,23668,23672,26748,28800,30852,31880,31884,32912,32916,33944,33948,34976,36004,36008,37036,39088,40116,40120,43196,45248,45252,46280,49356,50384,50388,51416,52444,54496,54500,55528,56556,56560,57588,57592,58620,58624,59652,59656,60684,62736,64788,65816,67868,67872,68900,69928,69932,70960,71988,73016,73020,74048,74052,76104,76108,77136,81236,84312,84316,85344,86372,86376,87404,89456,89460,90488,90492,91520,94596,94600,95628,95632,96660,96664,97692,97696,98724,99752,102828,102832,103860,103864,104892,104896,105924,105928,106956,107984,107988,109016,110044,110048,112100,112104,113132,113136,116212,117240,117244,119296,0};
short BUCKET_INDEX_BFS [8] = {0,22,34,49,68,84,103,123};

short FULL_CHILDREN_BUCKET_INDEX_BFS[128] = {0,3,6,7,9,10,11,0,13,15,17,18,20,0,21,22,0,23,0,24,26,0,27,0,0,29,0,30,0,31,32,34,36,38,39,41,0,42,43,0,0,45,0,46,48,0,0,49,50,52,53,0,54,56,57,59,61,63,65,0,66,0,67,68,0,69,71,72,74,75,76,78,0,80,82,0,0,0,83,0,0,84,86,87,89,0,90,92,94,0,0,95,97,99,101,103,104,0,0,105,107,109,111,113,114,116,117,0,119,121,0,0,123,124,0,126,0,0,0,0,0,0,0,0,0,0,0,0};
short FULL_PARENTS_BUCKET_INDEX_BFS[128] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126};
ap_uint<18>  bfstree_2_1 [64] = {1032,1036,1040,2068,2072,2076,3104,4132,4136,5164,6192,7220,7224,9276,9280,10308,10312,11340,12368,12372,13400,15452,16480,18532,20584,20588,21616,23668,23672,26748,28800,30852,31880,31884,32912,32916,33944,33948,34976,36004,36008,37036,39088,40116,40120,43196,45248,45252,46280,49356,50384,50388,51416,52444,54496,54500,55528,56556,56560,57588,57592,58620,58624};
ap_uint<18>  bfstree_2_2 [64] = {59652,59656,60684,62736,64788,65816,67868,67872,68900,69928,69932,70960,71988,73016,73020,74048,74052,76104,76108,77136,81236,84312,84316,85344,86372,86376,87404,89456,89460,90488,90492,91520,94596,94600,95628,95632,96660,96664,97692,97696,98724,99752,102828,102832,103860,103864,104892,104896,105924,105928,106956,107984,107988,109016,110044,110048,112100,112104,113132,113136,116212,117240,117244,0};
short BUCKET_INDEX_2_1 [8] = {0,13,22,29,34,45,49,59};
short BUCKET_INDEX_2_2 [8] = {0,15,21,29,40,50,60,-1};

ap_uint<18>  bfstree_4_1 [32] = {1032,1036,1040,2068,2072,2076,3104,4132,4136,5164,6192,7220,7224,9276,9280,10308,10312,11340,12368,12372,13400,15452,16480,18532,20584,20588,21616,23668,23672,26748,28800};
ap_uint<18>  bfstree_4_2 [32] = {30852,31880,31884,32912,32916,33944,33948,34976,36004,36008,37036,39088,40116,40120,43196,45248,45252,46280,49356,50384,50388,51416,52444,54496,54500,55528,56556,56560,57588,57592,58620,58624};
ap_uint<18>  bfstree_4_3 [32] = {59652,59656,60684,62736,64788,65816,67868,67872,68900,69928,69932,70960,71988,73016,73020,74048,74052,76104,76108,77136,81236,84312,84316,85344,86372,86376,87404,89456,89460,90488,90492,91520};
ap_uint<18>  bfstree_4_4 [32] = {94596,94600,95628,95632,96660,96664,97692,97696,98724,99752,102828,102832,103860,103864,104892,104896,105924,105928,106956,107984,107988,109016,110044,110048,112100,112104,113132,113136,116212,117240,117244,0};
short BUCKET_INDEX_4_1 [8] = {0,7,13,18,22,24,29,30};
short BUCKET_INDEX_4_2 [8] = {0,10,14,15,18,23,28,-1};
short BUCKET_INDEX_4_3 [8] = {0,9,15,20,21,24,29,-1};
short BUCKET_INDEX_4_4 [8] = {0,10,18,24,28,31,-1,-1};

ap_uint<18> dfstree [128] = { 1032, 2068, 5164, 11340, 2072, 6192, 12368, 20584, 26748, 31880, 34976, 31884, 36004, 36008, 43196, 20588, 12372, 21616, 28800, 32912, 37036, 32916, 2076, 7220, 13400, 7224, 1036, 3104, 1040, 4132, 9276, 15452, 23668, 23672, 30852, 33944, 39088, 45248, 49356, 52444, 56556, 60684, 68900, 56560, 45252, 50384, 50388, 54496, 57588, 62736, 69928, 76104, 84312, 84316, 89456, 94596, 99752, 109016, 94600, 89460, 95628, 95632, 102828, 110044, 110048, 102832, 76108, 85344, 90488, 96660, 103860, 112100, 112104, 103864, 113132, 113136, 96664, 104892, 104896, 90492, 97692, 105924, 116212, 105928, 117240, 117244, 97696, 106956, 69932, 77136, 86372, 91520, 98724, 107984, 119296, 107988, 86376, 57592, 54500, 58620, 64788, 70960, 58624, 65816, 71988, 33948, 40116, 46280, 51416, 55528, 59652, 59656, 67868, 73016, 73020, 81236, 87404, 67872, 74048, 74052, 40120, 9280, 16480, 4136, 10308, 10312, 18532, 0};
ap_uint<18> dfstree_1 [64] = { 1032,2068,5164,11340,2072,6192,12368,20584,26748,31880,34976,31884,36004,36008,43196,20588,12372,21616,28800,32912,37036,32916,2076,7220,13400,7224,1036,3104,1040,4132,9276,15452,23668,23672,30852,33944,39088,45248,49356,52444,56556,60684,68900,56560,45252,50384,50388,54496,57588,62736,69928,76104,84312,84316,89456,94596,99752,109016,94600,89460,95628,95632,102828,110044};
ap_uint<18> dfstree_2 [64] = {110048,102832,76108,85344,90488,96660,103860,112100,112104,103864,113132,113136,96664,104892,104896,90492,97692,105924,116212,105928,117240,117244,97696,106956,69932,77136,86372,91520,98724,107984,119296,107988,86376,57592,54500,58620,64788,70960,58624,65816,71988,33948,40116,46280,51416,55528,59652,59656,67868,73016,73020,81236,87404,67872,74048,74052,40120,9280,16480,4136,10308,10312,18532};
