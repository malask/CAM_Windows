int selected [2048] = {8,13,20,23,26,33,38,45,51,52,57,58,59,60,63,65,67,77,80,83,87,89,92,94,104,106,116,120,130,131,137,143,146,147,154,157,158,160,181,191,196,198,199,200,204,210,211,213,220,221,222,223,228,229,231,232,240,247,249,253,255,261,262,264,266,268,270,271,282,293,296,307,311,312,314,322,324,329,330,331,332,334,335,336,342,350,357,362,363,367,368,372,383,385,387,388,392,395,399,400,402,404,413,415,416,420,435,439,441,448,451,452,455,458,465,469,471,472,475,484,489,492,494,502,504,508,510,515,516,521,528,530,536,541,543,544,549,554,560,572,575,581,584,587,589,592,593,597,598,603,609,610,620,621,633,634,636,639,642,643,656,665,669,671,672,676,679,680,681,684,685,686,690,691,696,713,715,716,719,720,722,729,733,736,743,745,749,750,754,759,760,764,767,768,776,778,792,793,800,814,828,831,834,835,840,842,845,851,852,853,878,880,888,890,897,898,904,909,919,926,930,937,942,945,946,950,954,966,967,969,970,973,974,976,979,983,987,998,1000,1002,1003,1015,1018,1022,1024,1027,1029,1030,1035,1038,1040,1041,1044,1045,1049,1053,1055,1061,1064,1068,1070,1075,1079,1084,1087,1088,1092,1096,1100,1102,1108,1109,1110,1112,1115,1123,1129,1130,1132,1144,1152,1153,1154,1165,1167,1169,1171,1176,1189,1190,1194,1199,1213,1215,1218,1230,1231,1233,1245,1247,1251,1254,1255,1257,1259,1261,1266,1280,1282,1284,1289,1290,1291,1302,1308,1315,1317,1319,1320,1322,1328,1329,1338,1341,1342,1349,1351,1363,1371,1372,1374,1377,1383,1387,1388,1391,1402,1403,1417,1424,1425,1433,1435,1436,1444,1446,1451,1460,1464,1465,1486,1487,1496,1497,1500,1501,1506,1513,1529,1531,1537,1546,1547,1556,1565,1567,1568,1571,1573,1574,1575,1576,1582,1583,1587,1591,1600,1607,1610,1611,1614,1615,1616,1624,1625,1626,1631,1632,1633,1640,1649,1656,1658,1669,1672,1675,1677,1681,1687,1695,1706,1709,1714,1715,1718,1720,1721,1735,1739,1740,1741,1746,1747,1749,1754,1760,1765,1766,1767,1770,1771,1772,1775,1778,1779,1780,1785,1786,1789,1791,1792,1798,1799,1811,1812,1816,1828,1836,1839,1840,1844,1865,1867,1873,1876,1882,1884,1888,1890,1895,1896,1901,1907,1911,1918,1922,1929,1931,1932,1933,1936,1938,1940,1949,1954,1956,1959,1963,1964,1967,1972,1974,1975,1978,1983,1992,1993,1995,1997,2002,2007,2016,2018,2021,2022,2024,2027,2028,2033,2040,2045,2052,2056,2057,2058,2059,2062,2063,2068,2069,2070,2071,2075,2077,2078,2079,2080,2081,2086,2089,2092,2093,2099,2104,2110,2111,2116,2119,2120,2129,2132,2136,2138,2147,2157,2165,2167,2168,2169,2173,2181,2188,2191,2195,2198,2199,2208,2211,2215,2229,2231,2233,2234,2239,2241,2242,2244,2245,2246,2247,2248,2253,2256,2261,2264,2268,2270,2274,2280,2286,2289,2297,2298,2301,2304,2309,2315,2316,2317,2325,2326,2327,2328,2331,2332,2339,2341,2343,2345,2346,2347,2348,2350,2354,2355,2357,2362,2364,2367,2368,2373,2386,2390,2391,2392,2393,2396,2405,2407,2413,2426,2430,2432,2439,2445,2448,2449,2457,2460,2463,2466,2472,2474,2487,2496,2504,2506,2508,2509,2513,2514,2515,2516,2521,2523,2528,2530,2531,2537,2539,2541,2545,2551,2556,2557,2559,2561,2567,2569,2581,2582,2583,2586,2590,2592,2597,2600,2603,2605,2611,2616,2624,2631,2633,2645,2648,2650,2651,2661,2668,2669,2675,2678,2682,2687,2690,2692,2695,2704,2707,2710,2712,2713,2716,2723,2727,2730,2732,2737,2754,2756,2757,2759,2760,2761,2765,2771,2782,2785,2786,2792,2794,2796,2798,2801,2808,2814,2816,2818,2823,2828,2829,2830,2831,2834,2836,2842,2843,2844,2845,2846,2849,2858,2859,2863,2864,2866,2867,2873,2875,2880,2889,2894,2898,2901,2903,2908,2909,2911,2913,2920,2922,2927,2929,2944,2951,2952,2954,2956,2958,2968,2970,2982,2984,2987,2992,2995,2996,2999,3002,3007,3013,3014,3016,3018,3020,3024,3030,3034,3036,3043,3044,3045,3050,3052,3056,3059,3066,3067,3070,3075,3085,3089,3090,3095,3096,3103,3107,3108,3109,3119,3121,3126,3129,3130,3131,3133,3141,3143,3146,3149,3152,3159,3162,3165,3167,3169,3173,3181,3182,3183,3185,3188,3192,3194,3200,3202,3209,3211,3213,3217,3218,3221,3222,3226,3229,3233,3236,3242,3249,3256,3257,3263,3264,3267,3273,3278,3286,3292,3293,3312,3314,3319,3326,3327,3330,3339,3340,3348,3353,3357,3364,3367,3370,3371,3373,3375,3376,3380,3384,3389,3400,3403,3404,3416,3418,3424,3425,3436,3437,3441,3442,3451,3452,3459,3460,3463,3470,3482,3484,3486,3487,3494,3498,3499,3501,3510,3512,3513,3515,3516,3519,3521,3524,3533,3539,3541,3546,3548,3553,3556,3559,3562,3567,3568,3571,3572,3574,3580,3585,3588,3589,3591,3606,3608,3609,3610,3612,3614,3615,3618,3623,3631,3641,3644,3651,3653,3654,3658,3671,3677,3679,3683,3708,3710,3711,3712,3713,3720,3730,3744,3751,3759,3761,3763,3770,3776,3778,3782,3784,3790,3791,3793,3796,3804,3808,3811,3812,3813,3814,3817,3820,3822,3829,3830,3836,3837,3839,3844,3845,3850,3851,3856,3857,3861,3863,3864,3866,3867,3869,3870,3871,3872,3874,3877,3882,3885,3886,3887,3895,3897,3901,3912,3918,3929,3938,3941,3945,3947,3948,3950,3955,3958,3959,3965,3968,3970,3971,3972,3979,3981,3991,3997,4000,4015,4021,4023,4026,4029,4037,4039,4042,4044,4057,4069,4078,4080,4087,4092,4099,4101,4102,4104,4108,4109,4111,4116,4120,4123,4124,4125,4134,4148,4149,4150,4151,4156,4159,4163,4165,4177,4178,4179,4182,4184,4194,4195,4196,4197,4201,4202,4209,4213,4215,4218,4219,4223,4228,4229,4232,4241,4244,4246,4254,4255,4257,4268,4271,4281,4286,4288,4293,4297,4301,4302,4304,4308,4311,4314,4315,4316,4324,4325,4330,4332,4334,4348,4349,4351,4353,4357,4363,4367,4368,4373,4374,4375,4378,4390,4399,4409,4418,4429,4430,4439,4444,4446,4448,4450,4457,4466,4470,4475,4477,4483,4490,4495,4497,4504,4509,4514,4516,4520,4532,4534,4546,4557,4559,4561,4567,4569,4570,4572,4578,4584,4585,4595,4614,4616,4625,4627,4632,4636,4637,4642,4646,4649,4651,4654,4658,4679,4683,4686,4691,4694,4695,4702,4708,4711,4714,4727,4733,4734,4747,4753,4757,4761,4762,4765,4767,4768,4769,4771,4775,4779,4780,4784,4787,4797,4799,4804,4805,4806,4808,4810,4811,4817,4818,4823,4826,4830,4833,4837,4840,4841,4844,4847,4848,4852,4863,4864,4865,4869,4873,4876,4879,4885,4886,4892,4893,4897,4901,4908,4909,4912,4915,4918,4923,4925,4935,4937,4938,4945,4946,4947,4949,4958,4959,4962,4965,4973,4975,4977,4981,4982,4991,5002,5009,5011,5017,5019,5030,5034,5035,5043,5044,5045,5050,5053,5056,5061,5065,5066,5067,5068,5069,5074,5075,5076,5077,5079,5090,5092,5093,5094,5095,5096,5104,5105,5108,5111,5118,5119,5126,5128,5130,5132,5133,5135,5139,5140,5144,5146,5154,5156,5164,5166,5170,5172,5176,5178,5180,5181,5183,5194,5208,5210,5212,5217,5220,5228,5243,5246,5248,5249,5251,5262,5265,5269,5271,5277,5279,5283,5284,5289,5291,5296,5298,5301,5305,5307,5311,5315,5321,5322,5324,5328,5332,5337,5340,5341,5348,5354,5356,5358,5361,5362,5365,5366,5371,5373,5374,5379,5383,5400,5402,5404,5409,5415,5416,5419,5428,5431,5433,5437,5446,5450,5458,5461,5463,5473,5478,5479,5480,5482,5483,5486,5489,5492,5493,5494,5495,5496,5498,5511,5515,5517,5522,5525,5536,5541,5545,5546,5551,5553,5554,5556,5560,5568,5570,5572,5575,5583,5585,5589,5593,5596,5597,5600,5603,5604,5620,5622,5635,5636,5641,5645,5646,5654,5660,5661,5662,5663,5680,5682,5687,5700,5702,5704,5706,5709,5710,5711,5717,5725,5730,5739,5741,5742,5743,5746,5747,5756,5759,5760,5768,5775,5779,5780,5782,5783,5784,5789,5795,5799,5806,5811,5814,5823,5827,5839,5842,5849,5850,5858,5865,5868,5869,5880,5881,5888,5894,5895,5899,5906,5908,5915,5919,5923,5933,5936,5938,5942,5943,5947,5949,5951,5966,5970,5971,5974,5975,5989,5992,6001,6004,6008,6009,6011,6014,6019,6035,6040,6041,6058,6067,6068,6073,6074,6077,6085,6086,6088,6093,6095,6105,6106,6108,6117,6119,6124,6126,6136,6141,6143,6150,6155,6157,6158,6159,6161,6162,6163,6167,6169,6170,6171,6172,6178,6181,6182,6187,6188,6189,6195,6201,6202,6204,6208,6209,6212,6215,6217,6220,6226,6228,6230,6231,6237,6238,6244,6246,6247,6250,6251,6253,6264,6269,6277,6286,6291,6292,6294,6300,6303,6305,6307,6312,6315,6318,6319,6332,6335,6343,6349,6350,6354,6355,6365,6375,6379,6380,6388,6389,6390,6391,6394,6406,6410,6413,6414,6415,6422,6424,6427,6430,6433,6435,6441,6443,6446,6447,6450,6453,6460,6461,6464,6466,6467,6470,6473,6480,6489,6491,6494,6496,6499,6507,6509,6514,6516,6518,6520,6525,6529,6535,6538,6540,6541,6543,6545,6554,6557,6562,6563,6567,6568,6569,6574,6576,6579,6580,6583,6584,6592,6594,6598,6599,6601,6607,6608,6610,6615,6619,6620,6631,6637,6638,6645,6653,6661,6664,6665,6666,6671,6675,6703,6704,6705,6709,6710,6725,6726,6727,6736,6741,6746,6748,6754,6761,6766,6772,6773,6775,6777,6785,6791,6794,6796,6799,6800,6801,6804,6814,6817,6821,6824,6828,6830,6835,6840,6843,6851,6853,6858,6859,6861,6865,6867,6868,6870,6872,6877,6888,6892,6895,6898,6912,6915,6916,6917,6932,6945,6951,6955,6956,6959,6961,6964,6971,6977,6981,6984,6991,6994,6997,6998,7003,7006,7018,7020,7021,7025,7027,7033,7035,7036,7038,7039,7041,7046,7047,7048,7050,7053,7056,7059,7064,7065,7069,7072,7079,7080,7081,7082,7084,7085,7089,7094,7097,7098,7100,7103,7105,7115,7117,7130,7132,7133,7135,7136,7138,7140,7142,7151,7166,7170,7171,7178,7182,7190,7191,7196,7199,7203,7207,7209,7212,7220,7221,7222,7225,7226,7233,7246,7251,7253,7256,7258,7262,7267,7268,7271,7273,7283,7285,7287,7290,7294,7297,7302,7303,7308,7313,7328,7332,7333,7334,7339,7342,7344,7351,7353,7357,7360,7362,7369,7370,7371,7373,7375,7377,7378,7389,7392,7404,7406,7411,7416,7417,7424,7430,7431,7433,7439,7440,7442,7446,7457,7459,7462,7464,7465,7475,7476,7486,7501,7503,7504,7506,7514,7516,7519,7520,7521,7523,7525,7528,7529,7531,7532,7537,7538,7541,7542,7545,7546,7549,7550,7555,7557,7559,7564,7566,7567,7569,7570,7587,7599,7602,7608,7616,7621,7625,7626,7627,7629,7630,7637,7638,7640,7645,7648,7650,7654,7657,7658,7660,7664,7667,7669,7670,7673,7679,7682,7686,7694,7697,7698,7699,7705,7706,7710,7712,7726,7727,7734,7739,7741,7742,7744,7754,7756,7773,7777,7778,7780,7783,7784,7786,7790,7794,7796,7799,7803,7804,7805,7812,7819,7830,7831,7832,7835,7837,7838,7857,7858,7860,7861,7863,7869,7877,7879,7880,7887,7888,7890,7891,7892,7897,7898,7900,7905,7906,7907,7908,7915,7918,7922,7925,7926,7927,7937,7938,7942,7947,7959,7964,7971,7977,7978,7988,7993,7996,8000,8002,8004,8005,8011,8018,8021,8022,8025,8029,8031,8037,8038,8045,8050,8052,8054,8060,8063,8076,8079,8084,8091,8092,8097,8106,8115,8120,8121,8123,8125,8127,8131,8140,8142,8154,8155,8158,8166,8174,8175,8181,8186,8190};
int results_parents[2048] = {5,8,12,14,15,20,24,30,35,35,38,38,39,39,40,43,43,51,53,54,59,62,65,67,77,78,90,93,102,104,109,112,114,116,120,123,124,127,147,155,159,162,163,163,165,171,172,174,182,182,183,184,187,189,192,192,198,201,202,205,207,219,219,220,223,224,225,227,236,249,253,265,272,273,275,280,282,291,292,293,295,296,297,297,302,309,322,328,329,333,333,341,352,354,355,357,361,363,368,369,371,375,386,387,387,391,413,417,418,423,426,426,429,432,438,441,443,444,447,456,460,462,464,474,475,479,480,488,489,493,497,501,507,510,511,512,515,520,527,539,542,546,547,549,552,555,555,561,562,568,573,574,580,582,600,601,602,607,609,609,620,627,631,632,635,638,640,641,643,645,647,647,650,650,658,676,678,679,681,682,684,689,694,697,709,710,712,713,716,725,725,729,732,732,737,742,756,757,765,777,789,791,793,795,801,803,807,812,815,816,838,842,846,849,858,858,864,867,883,890,894,898,900,903,906,910,916,935,936,937,938,945,946,948,951,953,958,969,973,974,975,985,988,991,995,1001,1003,1004,1009,1013,1014,1015,1019,1019,1024,1027,1028,1033,1034,1036,1038,1042,1045,1050,1054,1055,1059,1062,1065,1066,1070,1071,1072,1074,1082,1088,1093,1094,1098,1108,1115,1115,1116,1126,1129,1135,1136,1139,1152,1152,1154,1163,1175,1178,1181,1192,1192,1194,1204,1208,1216,1219,1219,1221,1224,1225,1229,1248,1252,1254,1259,1260,1260,1270,1278,1289,1290,1292,1293,1294,1301,1301,1309,1311,1312,1317,1318,1334,1340,1340,1342,1343,1354,1359,1359,1362,1371,1372,1389,1397,1397,1404,1405,1406,1418,1421,1425,1438,1442,1443,1460,1460,1466,1467,1472,1475,1480,1491,1507,1508,1518,1528,1529,1540,1547,1549,1555,1558,1559,1559,1564,1565,1571,1571,1573,1577,1585,1590,1593,1593,1596,1596,1597,1605,1605,1606,1610,1611,1611,1617,1624,1632,1633,1641,1644,1650,1651,1656,1659,1668,1677,1681,1684,1687,1688,1693,1694,1709,1713,1714,1717,1722,1722,1723,1727,1734,1739,1740,1742,1745,1747,1748,1751,1753,1753,1754,1756,1757,1759,1761,1761,1767,1767,1779,1781,1784,1797,1802,1805,1806,1809,1828,1832,1839,1843,1847,1851,1853,1855,1859,1859,1864,1869,1874,1883,1886,1892,1893,1895,1896,1900,1903,1906,1915,1919,1921,1923,1927,1928,1933,1935,1940,1940,1943,1947,1954,1955,1956,1957,1960,1966,1973,1974,1976,1976,1977,1979,1980,1988,1998,2009,2012,2016,2017,2017,2018,2022,2023,2032,2033,2034,2034,2041,2042,2044,2044,2045,2045,2050,2052,2055,2055,2063,2067,2075,2075,2078,2084,2086,2091,2093,2096,2097,2104,2113,2120,2121,2123,2123,2125,2134,2141,2146,2149,2153,2153,2162,2163,2166,2179,2180,2182,2183,2190,2194,2194,2197,2197,2199,2200,2200,2205,2208,2213,2216,2221,2222,2225,2230,2240,2250,2255,2256,2257,2264,2266,2270,2270,2271,2277,2278,2279,2281,2287,2288,2295,2297,2301,2302,2303,2304,2304,2306,2311,2311,2312,2315,2317,2320,2321,2323,2334,2341,2341,2342,2344,2346,2355,2356,2364,2374,2377,2379,2387,2394,2397,2397,2405,2407,2410,2414,2424,2425,2437,2448,2461,2463,2464,2466,2468,2469,2469,2470,2474,2475,2478,2479,2480,2487,2488,2489,2491,2496,2502,2502,2504,2507,2513,2514,2525,2525,2526,2528,2532,2534,2539,2541,2543,2545,2549,2554,2564,2569,2570,2584,2586,2588,2589,2597,2606,2606,2611,2614,2618,2622,2623,2627,2629,2640,2642,2647,2649,2650,2654,2658,2662,2664,2667,2673,2689,2691,2691,2693,2694,2694,2698,2702,2714,2716,2716,2720,2722,2723,2731,2738,2744,2755,2756,2762,2769,2772,2773,2773,2774,2777,2781,2787,2792,2792,2793,2800,2802,2814,2814,2818,2820,2821,2822,2828,2829,2831,2842,2846,2850,2852,2853,2857,2858,2859,2862,2867,2869,2877,2878,2888,2892,2892,2895,2897,2898,2907,2908,2921,2922,2925,2930,2932,2933,2935,2937,2941,2945,2945,2947,2950,2952,2955,2962,2966,2971,2982,2982,2987,2992,2994,2998,3002,3010,3012,3014,3017,3031,3040,3040,3044,3045,3055,3060,3060,3063,3069,3071,3074,3076,3077,3077,3079,3087,3090,3091,3094,3097,3103,3105,3107,3109,3110,3115,3122,3123,3123,3125,3128,3130,3131,3135,3136,3143,3144,3147,3150,3150,3152,3155,3158,3162,3166,3170,3177,3182,3187,3188,3201,3203,3207,3214,3218,3224,3233,3234,3251,3252,3257,3263,3264,3268,3274,3276,3283,3298,3303,3307,3315,3317,3320,3321,3324,3325,3328,3332,3335,3342,3343,3346,3363,3364,3369,3370,3381,3382,3385,3385,3392,3392,3401,3401,3403,3408,3423,3425,3427,3427,3437,3443,3444,3448,3454,3455,3457,3460,3461,3463,3465,3469,3478,3483,3485,3488,3489,3493,3495,3498,3502,3508,3508,3510,3511,3512,3519,3524,3526,3528,3529,3543,3547,3547,3549,3550,3554,3554,3556,3559,3568,3580,3584,3591,3596,3598,3602,3614,3618,3622,3624,3652,3653,3654,3656,3657,3661,3677,3687,3696,3700,3701,3702,3710,3715,3717,3724,3725,3729,3730,3731,3736,3743,3748,3750,3751,3752,3753,3756,3758,3759,3766,3768,3774,3775,3776,3783,3784,3789,3790,3794,3795,3799,3802,3803,3804,3805,3806,3806,3807,3807,3810,3812,3815,3820,3820,3824,3833,3836,3842,3850,3855,3866,3875,3878,3881,3882,3882,3883,3890,3892,3893,3896,3902,3905,3906,3907,3916,3917,3923,3927,3928,3940,3945,3946,3948,3954,3971,3973,3979,3980,3988,3997,4002,4003,4012,4015,4019,4021,4021,4022,4025,4026,4027,4030,4035,4038,4038,4039,4051,4063,4065,4067,4068,4071,4075,4079,4081,4098,4098,4099,4101,4102,4113,4116,4116,4117,4119,4120,4127,4129,4131,4133,4133,4136,4140,4140,4142,4149,4151,4153,4159,4159,4161,4176,4179,4191,4195,4196,4201,4205,4209,4210,4211,4220,4222,4227,4227,4229,4234,4235,4241,4244,4246,4263,4264,4265,4266,4272,4278,4280,4281,4287,4288,4288,4294,4307,4320,4335,4344,4354,4357,4367,4372,4375,4377,4378,4386,4392,4396,4401,4402,4406,4414,4424,4425,4432,4436,4439,4443,4445,4455,4458,4472,4481,4482,4483,4490,4493,4494,4497,4504,4508,4509,4516,4533,4534,4545,4549,4553,4556,4558,4562,4564,4566,4567,4569,4572,4598,4601,4604,4609,4611,4618,4624,4629,4634,4635,4647,4652,4652,4662,4667,4670,4674,4675,4678,4679,4680,4680,4682,4686,4690,4695,4699,4702,4709,4711,4716,4719,4719,4721,4722,4723,4728,4731,4736,4738,4741,4744,4751,4754,4758,4760,4763,4765,4769,4779,4779,4780,4783,4787,4790,4792,4797,4797,4801,4803,4812,4817,4826,4826,4828,4834,4838,4848,4849,4859,4862,4862,4869,4869,4871,4872,4880,4881,4883,4885,4891,4894,4896,4903,4905,4918,4935,4941,4944,4948,4949,4958,4960,4960,4964,4965,4966,4974,4978,4984,4986,4995,4995,4997,4998,5001,5004,5005,5005,5006,5007,5019,5020,5021,5021,5024,5030,5036,5038,5040,5042,5047,5048,5052,5055,5056,5057,5058,5059,5061,5062,5066,5067,5079,5080,5088,5093,5095,5096,5103,5104,5105,5105,5106,5116,5132,5134,5136,5140,5144,5152,5169,5171,5173,5173,5176,5188,5189,5195,5196,5207,5209,5211,5212,5217,5219,5225,5226,5228,5232,5233,5240,5243,5251,5252,5253,5260,5262,5267,5269,5269,5277,5281,5283,5285,5286,5287,5289,5290,5294,5296,5296,5300,5302,5318,5320,5321,5331,5337,5339,5341,5353,5357,5359,5362,5367,5370,5376,5378,5380,5389,5395,5395,5396,5397,5397,5401,5403,5405,5406,5407,5408,5408,5410,5420,5428,5430,5438,5441,5454,5458,5462,5462,5475,5477,5477,5479,5482,5489,5490,5491,5494,5503,5505,5507,5511,5513,5514,5517,5518,5519,5538,5540,5550,5553,5557,5561,5561,5567,5576,5577,5578,5578,5596,5597,5600,5616,5621,5623,5627,5629,5630,5630,5636,5641,5646,5650,5655,5655,5656,5658,5659,5664,5668,5669,5673,5682,5685,5687,5688,5690,5690,5695,5704,5708,5712,5715,5718,5724,5729,5741,5742,5750,5751,5759,5770,5773,5774,5785,5787,5794,5801,5802,5805,5815,5816,5826,5828,5830,5839,5842,5844,5846,5848,5851,5853,5858,5871,5875,5876,5877,5878,5889,5891,5899,5902,5910,5910,5911,5914,5919,5932,5938,5938,5952,5961,5961,5964,5970,5974,5980,5982,5983,5986,5989,5998,6000,6002,6011,6012,6019,6020,6031,6038,6039,6047,6054,6056,6058,6058,6062,6062,6064,6069,6071,6071,6074,6074,6081,6087,6087,6096,6096,6097,6100,6107,6107,6108,6112,6112,6116,6117,6120,6122,6128,6130,6131,6131,6138,6139,6142,6144,6145,6147,6149,6150,6162,6166,6174,6179,6186,6187,6188,6191,6193,6194,6195,6200,6201,6206,6206,6221,6224,6230,6236,6236,6240,6245,6259,6266,6268,6268,6284,6285,6285,6286,6292,6301,6304,6305,6308,6308,6316,6317,6321,6324,6327,6331,6336,6338,6341,6341,6344,6347,6356,6357,6359,6362,6363,6366,6369,6378,6384,6388,6391,6396,6398,6408,6409,6414,6415,6417,6418,6423,6426,6431,6433,6436,6436,6438,6443,6457,6459,6462,6463,6471,6471,6473,6477,6480,6483,6483,6485,6486,6492,6496,6503,6503,6506,6512,6512,6513,6524,6526,6529,6541,6545,6545,6553,6563,6570,6573,6575,6576,6579,6582,6611,6611,6612,6614,6615,6630,6630,6631,6640,6645,6654,6655,6660,6669,6674,6680,6682,6684,6685,6694,6701,6704,6705,6708,6708,6710,6712,6724,6726,6731,6733,6739,6740,6745,6751,6753,6760,6764,6770,6770,6771,6775,6776,6777,6778,6780,6782,6794,6800,6802,6803,6820,6823,6825,6825,6847,6859,6864,6870,6872,6873,6874,6876,6881,6886,6888,6889,6896,6899,6902,6903,6911,6915,6928,6932,6932,6936,6937,6942,6943,6943,6944,6946,6947,6952,6955,6955,6956,6958,6961,6964,6970,6971,6973,6977,6982,6982,6984,6985,6988,6988,6993,6997,7000,7001,7002,7004,7006,7016,7017,7030,7031,7031,7033,7034,7039,7040,7041,7053,7069,7072,7073,7077,7081,7086,7087,7091,7093,7097,7100,7103,7105,7112,7112,7113,7115,7117,7121,7138,7143,7144,7146,7147,7152,7156,7157,7158,7160,7174,7175,7176,7181,7184,7193,7197,7197,7201,7206,7222,7224,7225,7226,7230,7233,7234,7241,7242,7246,7249,7252,7262,7263,7265,7268,7270,7271,7275,7286,7288,7297,7300,7305,7313,7315,7320,7324,7324,7325,7331,7332,7333,7337,7348,7351,7352,7355,7357,7368,7368,7380,7391,7392,7393,7394,7402,7403,7407,7407,7408,7409,7410,7411,7414,7415,7416,7420,7420,7422,7423,7424,7425,7427,7428,7431,7433,7435,7438,7440,7444,7445,7445,7465,7479,7482,7489,7496,7501,7504,7506,7506,7509,7509,7514,7515,7516,7522,7524,7526,7529,7533,7533,7535,7539,7542,7544,7544,7547,7552,7554,7562,7570,7573,7574,7574,7577,7578,7580,7581,7592,7592,7600,7602,7604,7605,7606,7614,7617,7632,7638,7638,7640,7642,7642,7646,7650,7653,7655,7657,7664,7664,7665,7671,7675,7685,7686,7687,7689,7691,7691,7705,7706,7709,7711,7714,7722,7727,7728,7729,7738,7740,7741,7742,7743,7747,7748,7751,7759,7760,7760,7762,7770,7774,7779,7782,7782,7784,7793,7794,7798,7804,7816,7821,7828,7835,7836,7850,7853,7857,7862,7864,7865,7865,7870,7874,7875,7876,7878,7883,7884,7892,7892,7898,7904,7905,7907,7912,7913,7927,7930,7933,7943,7944,7947,7955,7966,7971,7971,7973,7975,7976,7982,7988,7990,8004,8005,8006,8011,8021,8023,8027,8031,8035};
int results_childrens  [2745] = {13,22,33,34,35,36,37,0,49,57,58,0,76,77,78,79,0,0,86,87,0,0,91,92,94,104,108,0,0,115,118,0,131,132,135,136,147,148,153,154,166,167,168,0,176,177,179,180,181,182,0,193,194,197,0,0,236,237,240,241,242,243,244,245,246,252,0,0,0,263,264,265,0,266,0,272,273,275,276,277,0,289,292,293,296,297,302,303,304,306,0,0,0,310,323,324,331,334,0,0,0,352,353,357,358,0,363,0,364,365,366,0,0,369,0,0,388,393,394,395,0,398,399,0,0,0,415,416,0,0,423,0,0,0,0,435,0,438,0,0,466,467,468,469,476,480,481,482,0,485,486,0,495,496,497,498,499,500,503,504,0,516,517,0,522,532,0,537,540,541,548,549,0,0,561,563,567,568,0,577,578,587,588,590,591,0,0,612,613,0,0,625,626,628,0,0,632,0,0,642,643,644,645,656,657,0,0,0,0,677,678,0,681,682,0,700,701,704,0,707,713,714,716,717,718,719,722,723,0,724,730,731,735,750,751,753,754,0,0,0,764,769,773,774,779,781,782,0,785,0,0,0,799,804,805,806,813,815,0,833,834,0,0,866,867,872,0,874,0,880,881,886,892,893,894,0,917,0,924,926,927,935,936,937,938,0,948,949,956,0,962,963,969,0,972,973,974,0,0,0,0,998,999,1000,1001,1002,1005,1006,0,0,0,0,0,1028,1029,1041,0,0,1049,1053,1054,1056,1057,1065,1066,1069,1070,1072,1073,1074,1078,1079,1080,0,0,1088,0,1099,1105,1108,0,1114,1119,1120,0,1123,1128,1131,1135,1136,1137,1143,1144,1145,1146,1147,1149,1152,1153,1162,1167,0,0,1180,1189,1190,1191,1192,1193,1194,1203,1204,1206,0,1214,1226,1227,1233,1238,1239,0,0,0,0,1267,1268,1270,1277,1278,0,0,1284,1285,1286,1287,1288,1289,1292,1296,0,0,0,1314,1315,1316,1317,1318,0,0,1346,1348,1349,1352,1353,1354,1355,0,1360,1361,1368,1369,1373,1374,1375,1380,1381,0,1393,1394,1402,1403,1406,1407,1411,0,0,1415,1416,0,1431,1432,0,1443,0,1450,1451,1454,1455,1456,1457,1467,1468,0,1474,1475,1486,1487,1493,1494,1510,1511,0,1516,1517,0,1520,1521,1522,0,0,1547,0,0,1562,1563,1564,1565,0,1576,1577,0,1578,1582,1583,1586,1587,0,1588,1589,1590,0,1597,1598,1602,1603,1608,1609,1618,1619,0,1630,1631,1632,1633,1637,1638,1639,0,1649,1650,1651,1652,1654,1655,1656,1657,1658,1659,1666,1667,1674,1681,1682,1685,1686,1696,1699,1702,1703,1706,1709,1710,1715,1716,1722,1723,0,1735,1740,0,1742,1743,0,0,0,1765,1766,0,0,1771,0,1780,1781,0,0,1796,1797,1798,1799,1802,1803,1804,1805,1806,0,0,1811,0,1817,0,0,1823,1824,0,1829,1830,0,1845,1846,1847,1852,1864,1865,1870,1871,1873,0,1877,1902,1904,0,1912,1913,1916,1917,1920,0,1927,1928,1932,1933,0,1941,1945,1946,1952,1953,1957,1958,1965,1966,0,1967,1968,1973,0,1974,1975,1985,1992,1995,1996,2000,2001,2004,0,2008,2009,2015,2018,2019,2020,2025,0,0,2036,2037,0,0,0,2043,2055,2056,2059,2060,0,2061,2062,0,2064,2065,2066,2069,0,2080,2081,2089,2094,2095,0,0,2098,2099,2100,0,2105,2106,2107,2108,2109,2110,2111,2114,2115,2116,0,0,0,2120,2121,0,2130,2131,2132,2133,2141,2142,2146,2147,2155,0,2160,2163,2164,2165,2177,2180,0,2184,2185,0,2203,2212,2213,2216,2217,2218,2219,0,0,2237,0,2243,0,2246,2255,2256,0,2263,2278,0,0,2282,0,0,0,0,0,0,0,2288,2293,2294,2298,2299,0,2304,2305,2312,2313,2315,2316,2322,2323,0,0,2334,2341,0,2343,2344,2347,2348,0,2361,2362,2363,2364,2365,0,2376,0,0,2380,2381,2382,2383,0,2390,2391,0,2394,2395,2396,0,2397,0,2403,2404,2405,2406,2408,0,2413,2414,2415,2416,2417,2425,2437,2438,0,2440,2441,2442,2443,2444,0,2456,2457,2460,2465,2475,2476,0,2480,2481,2489,2492,2493,2496,2497,2498,2503,0,2506,2507,2509,2519,2521,2522,2537,2538,2550,2551,2559,2560,2563,2564,2566,2567,2568,2569,2570,2571,2576,2577,0,2585,2586,2588,0,2595,2596,2597,2599,2600,2604,2605,0,0,0,0,2620,2621,2627,2628,2631,2641,2642,2643,2644,0,2648,2652,2653,0,2661,0,2665,0,2675,2679,0,2697,2698,2699,2709,0,2713,2714,0,2733,0,2739,2743,2744,2747,2748,0,0,0,2762,0,0,2778,2779,2780,2781,2785,2786,2795,2796,0,0,0,0,0,2815,2816,0,0,2817,0,0,2825,2826,2838,2839,0,2841,2843,2844,0,0,0,2848,2854,2855,2858,2859,0,2863,2869,2870,2873,2874,2875,2876,2877,2878,2879,2880,0,0,2889,2890,2891,2892,2893,0,2894,2896,2909,2910,2911,2912,2914,2915,0,2917,2918,2919,2920,0,0,2931,2932,2945,2946,0,2957,2958,2960,2961,2963,2970,0,2973,2974,2980,2981,2983,2984,2989,2990,0,3011,3012,3019,3020,3022,3023,3026,3027,0,3035,0,3043,3044,0,3045,3046,3050,0,3053,3054,0,3059,3060,3064,3065,3068,3069,3070,3071,3073,3074,0,3077,0,0,3086,0,3092,3093,3094,3095,3096,3099,3101,3105,0,3113,3114,3115,3120,3127,3128,3138,3139,3142,3143,3144,3150,3151,0,3158,3159,3164,3165,0,3166,3167,0,3180,3186,3190,3191,3192,3193,3194,3197,3198,3206,3209,3210,0,3215,3216,3221,0,3229,3230,0,3234,0,3238,3239,3247,3248,3249,3250,3251,3252,0,3257,0,3259,0,0,3269,3270,0,0,3276,3277,3278,3279,0,3284,3287,0,3291,3292,3294,3299,3309,3310,3317,3318,3319,3326,3327,0,3336,3337,0,0,3350,0,0,0,0,0,3377,3378,3381,3382,3396,3397,3398,3407,3408,3412,3413,0,3418,3419,3422,3423,3425,3426,0,0,3430,3431,3432,0,3440,3448,3458,3463,3464,0,0,3478,0,3484,3485,3491,3492,3493,3494,0,3497,0,3507,0,3514,3515,3519,0,3537,3538,0,3543,3544,0,3554,3555,3559,3560,0,3570,3571,3574,3575,3577,3578,0,3580,3583,3585,3586,3594,3595,0,0,0,0,0,3618,3619,3622,3623,3627,0,3631,3632,3634,0,0,3641,3642,0,3647,3648,3649,3650,3651,3652,0,3662,3663,3664,3665,3666,3667,3668,3670,3671,3672,3673,3676,3677,3681,3682,0,3698,3699,0,3707,3709,3710,3711,3714,3715,3724,3725,3730,3731,3732,3733,3738,3739,0,3770,3771,3772,3773,3780,3781,3791,3792,3806,3812,3821,3822,0,3825,3826,0,3839,3840,0,3845,3851,3852,3853,0,3859,3865,3866,0,3875,3876,3877,3878,3879,3880,3881,0,3885,3886,0,3891,3892,0,3897,3898,0,0,3903,3904,3905,3911,3912,3913,3919,0,3923,3924,3925,3926,3927,3928,3929,3930,3931,3932,0,3934,3935,3936,3937,0,0,3947,3948,0,3952,3953,0,3962,3963,0,0,3977,3983,3984,4001,4002,0,4016,4017,4021,4022,4025,4026,0,4030,4031,0,0,4035,4036,0,0,4037,4038,4042,4043,4046,0,4069,4070,4074,4075,4091,4092,4101,4102,4105,4106,4109,4110,4114,4115,0,4125,4126,4129,4130,4138,4152,4153,4161,4162,0,0,4174,4179,4180,4182,4183,4184,4187,0,0,4192,4195,4196,4202,4203,0,4206,4207,4220,4238,4239,4240,4241,4242,4243,4244,4252,4254,4255,4258,4259,0,4269,4270,4271,4276,4278,4285,4286,4287,4288,4289,0,4293,4294,0,4301,0,0,0,0,0,0,4316,4317,4320,4321,4330,4332,4334,4339,0,4340,0,4356,4368,4372,4374,4375,0,4380,4386,0,0,4391,4394,0,4395,0,4403,0,4406,4407,4408,4421,4422,4423,4424,4426,4427,0,4430,4431,0,4439,4440,4441,0,0,4445,4446,4449,4450,4462,4463,4473,4474,0,0,4502,4503,4513,4514,4518,4519,4521,0,4524,4533,4538,4543,4550,4551,4554,4555,4560,4561,4567,4568,4571,4572,4578,4579,4585,4586,4590,4591,4594,4595,0,4612,4613,4616,4626,0,4638,4639,0,4651,4654,4655,4656,4657,4658,4663,0,4668,4676,4677,0,0,4703,4704,4706,4707,0,4715,4716,0,4725,4726,4729,4730,4731,4732,4735,4741,4742,4766,4767,4772,4775,0,0,4780,4787,4788,4796,4799,0,4814,4815,0,4821,0,4838,0,0,4846,4848,4849,4851,0,4852,4855,4856,0,4863,4864,4865,4870,4872,4873,4885,4886,0,4894,4895,0,0,0,0,4896,4901,0,0,4908,4909,0,0,4917,0,4919,4920,0,4922,4923,4928,4939,4940,4941,0,4945,4946,4950,4953,0,4965,4966,4967,0,4974,0,0,4983,0,0,4986,4987,4991,4992,0,0,5002,5003,5004,5005,0,5012,5013,5014,5015,5016,5019,5030,5031,5032,5033,5038,5039,5044,0,0,0,5054,5055,0,5071,5072,0,0,5087,5089,5090,5096,5102,0,5113,5114,0,5123,0,5129,5130,5138,5139,5143,5144,5145,5146,0,5147,5148,0,0,0,5152,5154,5155,0,0,5166,5167,5168,5169,5170,5171,5172,5178,5179,5180,5181,0,0,5197,5198,5199,0,0,5205,5206,5208,5209,0,0,5216,5217,5220,5221,0,5231,5233,5240,5241,5242,5244,5247,5251,0,0,5256,5258,0,5278,5281,5282,5284,5285,5289,5290,0,5300,5301,5315,5317,5318,5319,5320,5321,5331,5332,0,5340,5341,5344,5348,5349,0,5355,5356,5357,5364,5365,5367,5373,5374,5376,5377,5381,5382,5386,5388,5389,0,5394,5403,5404,5405,0,0,5410,5415,5418,5419,5420,5426,0,5429,5430,0,5435,5436,5437,5438,5442,5443,5444,5445,0,0,5454,0,5467,5468,5485,5488,5490,0,5503,5504,5505,5508,5509,5515,5516,0,0,0,0,0,5540,5541,5543,5544,5547,5550,5555,5556,5557,5559,5560,5561,5562,5565,5568,5569,0,5573,5574,5575,5576,5577,0,5593,5594,5598,5600,5601,5608,5609,5612,5613,5618,5619,5624,5629,5630,0,0,5636,5637,0,5639,5640,5644,0,0,5656,5657,5659,0,5668,5672,5673,5677,5678,5680,5681,5682,5683,5687,5688,5689,5690,0,0,0,5715,5716,5717,5724,5725,5729,5730,5731,0,0,5749,5750,5751,5752,5753,5754,0,5775,5780,5781,0,0,5794,5795,5798,5801,5802,5803,5804,5812,5813,0,5828,0,5839,5840,5841,5842,5843,5844,0,5845,0,5857,5858,0,5862,5863,5870,5871,5873,0,5875,5876,5877,5878,0,5889,5890,5892,5900,5903,5904,5905,0,5916,5917,5933,5934,5936,5944,5945,5946,5951,5952,0,5961,5962,5979,0,5987,5988,0,5996,5997,6000,6001,6005,6006,6007,6015,6018,6019,6024,6036,0,6040,6041,0,0,6050,6051,6052,6053,6056,0,6074,6075,6077,0,6095,0,0,0,0,6112,6113,6116,6117,0,6124,0,0,6144,6145,6158,6159,6165,6166,0,6171,6172,0,6180,0,0,6184,6185,0,6200,0,6203,6204,6214,6215,6216,6222,6223,0,6235,6241,6242,6245,6253,0,6258,6259,6260,6261,6262,6263,6264,6265,6270,6271,6272,6273,0,6274,6275,6283,6284,0,0,6292,6293,6294,6295,6296,6297,6307,6308,6314,6315,6316,0,6322,0,0,6326,6327,0,6331,6338,6339,6340,6341,6343,6344,0,6351,6352,0,0,0,0,6358,6359,0,0,0,0,6391,6393,6394,6395,6398,6399,6405,6409,6412,6413,0,6418,6420,6421,0,0,6436,6439,6440,6449,0,0,6458,6459,0,0,6478,6482,6483,6484,6491,6492,0,6493,6494,0,6503,6504,6510,0,6513,6514,6515,6516,6524,0,6530,6531,6534,6538,0,0,6545,0,0,0,0,6558,6559,6560,0,6564,6565,0,0,6569,6570,6576,6577,6588,6589,6591,6593,6594,0,0,6602,6603,6611,0,0,0,6617,6618,6620,6623,6624,6628,6629,6630,6631,6634,6637,6638,6646,6648,6652,6653,6658,6659,0,0,0,6666,6667,6671,0,6676,6677,6678,6679,0,0,6691,6692,6693,6694,6696,6697,6700,6701,0,6702,6710,6714,6715,6716,6717,6727,6728,0,6733,6734,6740,6741,0,6756,0,0,0,6763,6764,0,0,6794,6795,6796,6797,0,6801,6815,6816,6817,0,0,6831,0,0,6845,6846,0,0,0,6862,6863,6865,6868,6869,0,0,6888,6889,0,6891,6892,6893,6894,0,0,6909,6913,0,0,6920,6921,6925,6929,0,6933,6936,6937,6943,6944,6945,0,0,6952,6953,0,6954,6955,6956,6957,6965,6966,6981,6982,0,6990,0,0,7006,7007,7008,7009,0,7020,7021,0,0,7047,7048,7049,7050,7054,7055,7056,7057,7059,7060,7065,7066,7072,7078,7081,7088,7091,7094,0,0,7105,0,7120,0,7124,7127,7128,7135,0,7137,0,7138,7139,7142,7143,7146,7147,7148,7149,0,7151,7152,0,7156,0,0,7165,7166,7169,7170,0,7180,7181,7182,7183,7184,7186,7187,7188,7193,7194,0,7203,7204,7207,7209,7210,7212,7225,7226,7239,7242,7243,0,0,7244,7245,7246,7248,7249,0,7261,7277,7278,0,7280,7288,7291,7292,7296,0,7301,7304,7305,7312,0,7315,7316,7319,7320,7327,0,7328,7329,7333,7334,7342,7357,7358,7361,0,0,0,7369,7372,7373,7374,7376,7377,0,7386,0,7390,7391,7394,7395,7401,7404,7408,7409,7410,7413,7416,0,7440,7441,7442,0,7447,7448,7449,7451,7459,7460,7463,7465,7468,7469,0,0,0,7477,7478,0,7482,7483,7484,0,7502,7503,0,7517,7518,7527,7528,7532,7533,7534,7544,7545,7553,7554,7555,7557,7565,7566,0,0,7579,0,7583,7585,7586,7587,0,7598,0,7621,7622,7624,7625,7626,7627,7637,7639,7640,0,7643,7644,7646,0,7653,7654,0,7655,7656,0,7662,7665,7666,7667,7671,7672,0,0,7676,7677,0,0,7684,7685,7689,7690,0,7691,7693,7694,7719,7732,7733,7738,7739,7747,7748,0,0,7763,7764,7765,0,7768,7769,7770,7771,7776,7777,7778,7780,7781,0,7788,7790,7795,7799,0,0,7803,7804,7807,7809,7810,7811,7815,7822,7823,7827,7828,7831,7842,7843,7846,7847,7848,7849,7857,7858,0,0,7876,7877,0,0,7890,7891,7894,7903,0,0,0,0,7923,0,7927,7929,0,7938,7939,0,0,7947,0,7954,7961,7974,0,7975,7977,7980,7981,7982,7996,0,0,0,8001,8008,8009,8024,0,8027,8028,0,8035,0,8036,8037,8038,0,8045,8048,8052,8053,0,8054,8055,8056,0,0,8071,8073,8074,0,8075,8076,0,0,0,8096,8097,0,0,8120,8121,8128,0,8140,8141,8144,0,0,8150,8153,8154,8155,8156,8166,8173,8174,0,0,8183,8185,8186,8192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
