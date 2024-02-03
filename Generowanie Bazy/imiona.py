from random import randint

names = ['Adam', 'Andrzej', 'Bartlomiej', 'Cezary', 'Dawid', 'Dominik', 'Emil', 'Fabian', 'Grzegorz', 'Jakub', 'Jan', 'Jerzy', 'Kacper', 'Karol', 'Krystian', 'Lukasz', 'Marek', 'Mariusz', 'Mateusz', 'Michal', 'Piotr', 'Radoslaw', 'Rafal', 'Robert', 'Szymon', 'Tomasz', 'Wojciech', 'Zbigniew', 'Bartosz', 'Dariusz', 'Damian', 'Maciej', 'Marcin', 'Przemyslaw', 'Stanislaw', 'Wladyslaw', 'Kazimierz', 'Tadeusz', 'Henryk', 'Ryszard', 'Marek', 'Jaroslaw', 'Adam', 'Milosz', 'Krzysztof', 'Leszek', 'Piotr', 'Pawel', 'Robert', 'Agata', 'Aleksandra', 'Alicja', 'Aneta', 'Anna', 'Barbara', 'Beata', 'Dorota', 'Elzbieta', 'Ewa', 'Halina', 'Iwona', 'Joanna', 'Karolina', 'Kasia', 'Klaudia', 'Konstancja', 'Magdalena', 'Malgorzata', 'Marta', 'Monika', 'Natalia', 'Paulina', 'Renata', 'Sabina', 'Sylwia', 'Teresa', 'Urszula', 'Wioletta', 'Zofia', 'Agnieszka', 'Edyta', 'Ewelina', 'Gabriela', 'Iwelina', 'Jadwiga', 'Katarzyna', 'Paulina', 'Martyna', 'Oliwia', 'Patrycja', 'Kinga', 'Justyna', 'Sylwia', 'Natalia', 'Joanna', 'Magdalena', 'Marta', 'Dorota', 'Karolina']

numery = [429159888, 741262132, 980138889, 432407240, 450118026, 700997325, 671733866, 947080352, 513659531, 464116252, 520408728, 490126545, 959669201, 578865307, 995728428, 765812201, 551061470, 607309631, 947611556, 779267707, 737255351, 518627601, 544870946, 449804152, 604050118, 437034833, 459831165, 498096662, 849157030, 480442582, 953999646, 525811346, 556709121, 904507571, 914336864, 948109334, 731793127, 912030689, 816511869, 690923891, 753892340, 513841759, 430683743, 907756551, 691886012, 740437494, 431882237, 440272203, 998819629, 711744266, 463856004, 613838573, 965722975, 457150111, 847756628, 909592219, 466872724, 996760136, 580665122, 791358279, 443993968, 437129619, 708518894, 649042106, 443501569, 982807418, 421403073, 671089999, 446380572, 484557242, 521762023, 690478447, 754398247, 746707739, 763269371, 820221817, 985175287, 675218540, 551332523, 740553123, 926400091, 886146298, 766592878, 778581498, 417995237, 662178887, 631566945, 881183171, 911261278, 926559549, 541531242, 995098612, 505687228, 795838571, 703020919, 804825505, 843051641, 971645846, 431955793, 615960214, 607056921, 679312360, 445057763, 507425899, 524404457, 611400138, 427222573, 559735585, 481884923, 627573176, 861539457, 411281509, 890569999, 909150372, 658964757, 667721970, 635879435, 573815579, 806483684, 551207865, 977160264, 654804403, 967025932, 847517797, 880826108, 519606026, 862342350, 669722078, 756291981, 567747096, 567018560, 403010606, 849569070, 665365936, 923328022, 992018027, 840690075, 855203465, 559783706, 914620989, 920916899, 489580074, 781017709, 699370783, 861444294, 680931768, 573651345, 980751008, 749466275, 823616891, 471166785, 960941736, 753579004, 803114184, 761804710, 862598139, 532613678, 614014896, 584483122, 737052985, 400101685, 418368700, 847867162, 738334281, 979499614, 539419484, 894432387, 992029325, 547956492, 753353232, 516765524, 845889272, 554466257, 944308999, 426580816, 530150140, 971245780, 795134608, 432137298, 401948659, 589263684, 915896543, 806378909, 666696758, 556525966, 821658183, 881267974, 407161044, 512397394, 502453194, 443355703, 691508368, 627870224, 981632237, 615066110, 771077950, 692899987, 530072683, 751081223, 793321043, 877966437, 671131158, 529139208, 461525251, 833670361, 422123602, 849381914, 611485247, 812113166, 417321795, 921111100, 811184661, 709505930, 713177055, 436790167, 642942560, 557794235, 771734742, 889580099, 521127054, 515342885, 612241067, 693772642, 421552308, 963357968, 992474708, 569310496, 853717988, 871079778, 577536050, 640804209, 621388215, 700429780, 502690850, 857921383, 723473956, 703001924, 830006606, 711385959, 469651570, 911560529, 708118511, 633082501, 893618722, 678628900, 778538430, 934569953, 881834309, 943647458, 581524772, 703503490, 755705548, 877776144, 566151828, 567288062, 718224194, 409037515, 863120609, 872081602, 405788929, 969919999, 669229643, 765208172, 890590679, 787449745, 563384365, 890676643, 995174717, 991947939, 454464036, 717606852, 814332289, 424500960, 845688291, 649884850, 668534355, 770728883, 421974870, 929214576, 483101537, 603961258, 656865957, 564568420, 857316566, 817012381, 652926240, 727113321, 799783030, 771037306, 458714798, 585209456, 627950831, 818251762, 605757618, 739585455, 554010869, 523397444, 404912737, 720447117, 877546262, 978761123, 674695408, 850948670, 544401898, 466107461, 663976892, 523699140, 606924900, 506352315, 463670884, 405822912, 561348185, 833934877, 817667493, 529181468, 898239468, 985851818, 490570410, 753666282, 595244750, 900763496, 496208621, 960781080, 846467971, 425788926, 455099461, 978722614, 775113309, 766279774, 883791869, 907680352, 676421473, 904699213, 676368672, 976434989, 878117227, 530314717, 715114988, 526212517, 586272631, 964445664, 621084530, 582208072, 857613256, 707383883, 919289680, 505404993, 683902922, 609448103, 789105154, 794388566, 728056545, 693775487, 904857215, 863177223, 803198999, 865038496, 735249791, 870819651, 470968340, 847498387, 699614231, 846386488, 476067969, 878432690, 876201066, 405551942, 903013115, 475467705, 652055825, 675008950, 850698285, 848449781, 765373684, 429172972, 539637734, 708519312, 911457785, 518327696, 657109323, 527454578, 568220486, 885501737, 685626938, 743516253, 609398666, 625111424, 496469942, 499659648, 598117889, 542851022, 435929502, 559774504, 978867874, 557514004, 494853462, 762918298, 443693252, 654158981, 466457615, 422580285, 512379499, 743111447, 704584087, 952488252, 719921363, 783293600, 588010742, 664056222, 941908345, 956189200, 424716759, 856342053, 966159335, 841928091, 633543162, 869759750, 872569707, 682108484, 902904648, 639676022, 606288377, 610433171, 930550091, 749192837, 442333547, 730228932, 645641574, 883275375, 610036231, 789915978, 879499386, 448454458, 559901038, 991672130, 762025149, 737015697, 627229048, 758423424, 787448758, 979611748, 737615219, 639238228, 523228392, 459016748, 644102198, 772267588, 630331031, 514275117, 529573704, 462372739, 738523491, 549150844, 759198931, 858766275, 878164783, 542881737, 688996267, 623161388, 586552934, 998262037, 889409174, 518762757, 710227724, 739223242, 847319581, 874662085, 452533797, 986919285, 400721776, 898958883, 462671317, 884795869, 555792416, 962748398, 400903775, 842513227, 901830068, 535012457, 500157189, 415492604, 493103618, 410897300, 844895143, 567927652, 877522062, 401227022, 494933277, 668005055, 645947036, 673460650, 613442447, 669855898, 565949057, 596395460, 969451720, 750092484, 502449217, 837725158, 555615171, 579775643, 520456688, 666622746, 741580422, 565456111, 672602535, 531759918, 857295638, 605816236, 748089692, 966170485, 490015398, 906991656, 926823677, 799795702, 863996595, 736802934, 795977696, 668642897, 716832068, 822074277, 818158750, 931103778, 824383630, 553301118, 811435986, 906045106, 779946458, 699999872, 691504896, 838291260, 980373581, 544544074, 579429675, 815929247, 884503758, 416313875, 887558184, 627311869, 820448858, 970490215, 538212312, 840252100, 693657931, 782775105, 812867639, 415136828, 709426314, 774037813, 665611445, 574875013, 541654379, 477870634, 417123761, 721835635, 877825566, 933858476, 700670050, 415232136, 623851139, 564047494, 647607023, 434402392, 771929151, 618373910, 909778265, 916396869, 699024651, 509598625, 826870984, 971815779, 690402571, 584296181, 457770631, 414212326, 443797184, 986474656, 875087467, 490682480, 755922241, 937741185, 492785626, 401331515, 865934742, 619633207, 443517528, 456744943, 814261363, 852496286, 479958510, 970254182, 625840408, 654166970, 430362223, 566005196, 931792529, 848072218, 448320112, 977831915, 663045498, 653219124, 619940338, 871665671, 694482049, 853442679, 895866888, 813443831, 911595755, 473690098, 934729507, 746095035, 927094250, 509723439, 478987602, 435534902, 464489223, 460400498, 833635540, 481089342, 468032629, 545625618, 878881319, 998513482, 606410092, 459603180, 963213630, 767309495, 546527948, 486859716, 597574917, 990419185, 476438991, 889240925, 859234715, 764523263, 507218231, 843840031, 620813179, 930550734, 542064157, 767094611, 948693061, 622471625, 938306068, 839185788, 753939770, 507861725, 902473783, 477725586, 492995425, 928733163, 523237228, 987812719, 439506498, 999353932, 984438849, 719092961, 707843481, 426817603, 834175601, 667494217, 948840895, 837790193, 478347713, 532786808, 504198408, 786070859, 556819328, 564762874, 432489311, 821506767, 936462973, 753897007, 875674155, 945177811, 706302221, 443733112, 704203886, 749001245, 458920273, 540382466, 692974381, 989127507, 926549377, 735008928, 823268759, 772915283, 931962867, 804539516, 990862811, 475206802, 795275439, 420698144, 565885890, 912848733, 421971465, 652089049, 554020520, 475432242, 520981837, 514783640, 537846378, 540407348, 819593247, 483307710, 930532345, 720830842, 792363254, 903291571, 979646464, 806862059, 600432223, 462593206, 999032126, 932879360, 761224163, 940173980, 436311903, 954066096, 859922607, 846658313, 662960277, 466267340, 478735317, 604363434, 657323834, 451664755, 576501333, 498212029, 430380730, 910433396, 514889598, 490237326, 437369179, 712032660, 807087945, 929804675, 731669342, 713000810, 899290270, 501137072, 616300787, 636956381, 545623776, 644553407, 483626232, 767490638, 428111045, 850802033, 717413738, 895509964, 456358522, 923602035, 452965099, 565630037, 557301683, 921143016, 508861352, 697861937, 527659121, 495635090, 883217361, 867228015, 997837340, 513269890, 905530120, 624871492, 681056271, 420373682, 713084467, 890498642, 465188438, 510066650, 512010411, 527229027, 845700115, 791069836, 880442006, 624597741, 887899043, 439150366, 702079562, 727325597, 867905349, 574221117, 542138819, 823160475, 797724357, 786503466, 922892364, 493829934, 915906879, 446640321, 837245887, 411268531, 493240952, 870019973, 909399587, 855923466, 552006011, 576408100, 497805777, 522963790, 796136683, 866570610, 556640652, 402179135, 915564917, 473473836, 741248131, 688286347, 955618678, 760871050, 599283815, 480987828, 540287657, 694720649, 771857098, 507530488, 510970048, 501047460, 968256448, 831708469, 878258053, 531792867, 612566805, 552653893, 954174813, 479045525, 730012375, 451064351, 950386256, 415628970, 597194623, 956574352, 987815536, 579306923, 922773832, 598141417, 463080719, 826077428, 769823919, 818462405, 653664677, 482485258, 856494501, 903292001, 536156743, 948914919, 597002938, 590586270, 497379513, 820210138, 980612905, 542468441, 447499152, 531591914, 436452821, 564275334, 972399514, 523356099, 905455429, 458126146, 422113545, 656816722, 976996455, 597304471, 998795525, 870148181, 679124840, 685168953, 681877809, 873001137, 458626252, 600053943, 486361362, 520028239, 666832859, 427097040, 962852278, 493174451, 427979362, 967541127, 477027969, 857570554, 805140137, 584446820, 761305287, 524465912, 462871374, 593825155, 876334539, 849906433, 687584520, 411945289, 955129531, 665749879, 974980425, 785264341, 672509486, 782551879, 891922482, 718846428, 943430459, 407842483, 710177255, 830003760, 415569085, 571956499, 666029716, 590584664, 998020618, 744473007, 647071543, 498277437, 450624146, 860507959, 615962622, 674838774, 831667242, 929682228, 961033909, 400327998, 481388491, 645669839, 713075101, 723533773, 889703864, 717234019, 989549017, 654244541, 996136724, 758956997, 470565737, 473630350, 948781121, 801317436, 644689319, 731712168, 434492967, 597692558, 732536295, 995206059, 989115608, 580077253, 411272907, 739842085, 897743406, 535525769, 658459502, 455259592, 423378976, 745940946, 735018149, 485216957, 970013932, 594310535, 939467765, 805635059, 955321233, 484884756, 983007306, 515528370, 462498589, 946674997, 784044413, 898275909, 454128086, 996319140, 708655586, 793263497, 534710612, 926019353, 643541219, 953437716, 737009974, 547000337, 965240942, 824789270, 960869598, 837202960, 526060721, 464100370, 679612332, 621196131, 817234298, 719151080, 655325677, 786958788, 890853546, 497054409, 690576801, 946727790, 985166522, 491704122, 748646234, 470430256, 928239614, 967992346, 878814894]

surnames = ['Nowak', 'Kowalski', 'Wisniewski', 'Wojcik', 'Kowalczyk', 'Kaminski', 'Lewandowski', 'Zielinski', 'Szymanski', 'Wozniak', 'Dabrowski', 'Kozlowski', 'Jankowski', 'Mazur', 'Wojciechowski', 'Krawczyk', 'Kaczmarek', 'Piotrowski', 'Grabowski', 'Nowakowski', 'Pawlowski', 'Michalski', 'Krol', 'Majewski', 'Szewczyk', 'Ostrowski', 'Baran', 'Przybylski', 'Lukasiewicz', 'Wrobel', 'Adamczyk', 'Czarnecki', 'Andrzejewski', 'Pawlak', 'Gorski', 'Kwiatkowski', 'Kucharski', 'Wilk', 'Kostrzewa', 'Cieslak', 'Maciejewski', 'Janusz', 'Urban', 'Zajac', 'Kuklinski', 'Zalewski', 'Wroblewski', 'Blaszczyk', 'Grabarczyk', 'Nowicki', 'Kopec', 'Gajewski', 'Kowal', 'Markowski', 'Kujawa', 'Zdunek', 'Sobczak', 'Glowacki', 'Wieczorek', 'Koperski', 'Czyz', 'Kurowski', 'Zieminski', 'Gorniak', 'Kupiec', 'Cegielski', 'Sowinski', 'Marcinkowski', 'Walczak', 'Kosecki', 'Cislowski', 'Piasecki', 'Glinski', 'Blaszyk', 'Zajac', 'Kabala', 'Zawadzki', 'Słowinski', 'Gacek', 'Wdowiak', 'Wrzos', 'Urbanowski', 'Deren', 'Skiba', 'Wolski', 'Bialek', 'Fraczek', 'Ciecierski', 'Jabłonski', 'Rudnicki', 'Piatkowski', 'Kulesza', 'Szczygiel', 'Brzozowski', 'Goral', 'Kostka', 'Kocieba', 'Zdziechowski', 'Klimczak']

data_zatrudnienia = ['21-11-2022', '11-11-2012', '30-10-2012', '12-3-2020', '2-6-2012', '1-6-2012', '4-3-2019', '18-9-2018', '23-10-2019', '4-6-2016', '16-10-2018', '1-12-2018', '15-4-2015', '5-11-2012', '15-3-2012', '15-9-2014', '7-6-2013', '25-6-2022', '18-9-2022', '16-4-2022', '21-8-2016', '9-2-2014', '17-7-2015', '28-4-2022', '24-12-2012', '28-3-2015', '8-12-2013', '20-1-2018', '1-11-2015', '18-8-2017', '6-5-2021', '25-6-2021', '5-12-2018', '13-12-2012', '8-3-2012', '17-5-2014', '18-2-2014', '27-9-2017', '28-6-2020', '4-1-2021', '5-8-2018', '15-1-2022', '1-1-2012', '21-10-2018', '12-9-2017', '25-3-2022', '6-11-2021', '18-1-2014', '18-9-2017', '1-2-2022', '2-12-2019', '7-8-2013', '4-11-2022', '3-9-2014', '18-4-2022', '28-4-2022', '25-10-2021', '29-10-2013', '16-2-2012', '4-10-2015', '12-12-2015', '22-2-2017', '29-5-2016', '11-6-2016', '6-3-2015', '16-1-2022', '7-9-2020', '19-12-2018', '4-4-2014', '22-10-2018', '25-8-2013', '19-10-2021', '24-4-2019', '2-12-2016', '1-4-2021', '26-6-2015', '15-9-2021', '8-8-2018', '28-8-2018', '28-9-2022', '9-11-2016', '10-7-2020', '21-7-2020', '26-12-2012', '2-11-2021', '30-1-2017', '24-11-2013', '28-9-2018', '20-11-2016', '25-10-2017', '21-8-2020', '24-11-2022', '6-4-2016', '25-8-2013', '19-7-2016', '10-5-2021', '5-7-2022', '28-7-2017', '29-7-2016', '16-8-2013', '21-10-2014', '12-11-2022', '11-3-2016', '13-6-2015', '29-2-2015', '15-3-2015', '5-1-2021', '16-9-2018', '6-10-2022', '8-12-2019', '13-12-2017', '27-6-2021', '24-2-2014', '7-10-2020', '27-8-2015', '8-3-2014', '25-12-2019', '29-2-2021', '17-8-2016', '23-4-2016', '12-1-2020', '30-2-2019', '1-1-2021', '20-4-2020', '15-7-2022', '24-2-2020', '24-2-2014', '9-1-2016', '16-4-2021', '12-4-2020', '13-6-2018', '8-4-2014', '19-1-2021', '4-3-2021', '17-5-2012', '9-5-2020', '22-8-2015', '13-1-2013', '26-1-2021', '19-8-2022', '14-6-2015', '3-8-2018', '6-12-2021', '25-3-2012', '9-3-2020', '27-12-2020', '21-8-2021', '30-5-2014', '29-10-2016', '4-11-2012', '14-8-2021', '15-7-2021', '26-9-2017', '11-10-2017', '10-2-2017', '23-12-2014', '2-11-2012', '9-11-2014', '30-1-2017', '25-4-2019', '16-2-2017', '8-6-2017', '26-4-2021', '24-11-2016', '22-8-2018', '6-8-2018', '25-4-2014', '27-2-2013', '15-9-2014', '2-6-2013', '21-3-2016', '14-4-2018', '14-1-2017', '1-2-2012', '24-8-2022', '14-12-2019', '26-12-2022', '9-10-2019', '16-6-2017', '2-9-2022', '21-6-2015', '18-6-2013', '1-2-2017', '24-5-2021', '22-8-2020', '10-9-2013', '14-2-2021', '7-10-2021', '2-5-2015', '7-2-2019', '24-7-2013', '12-11-2016', '22-12-2021', '8-7-2022', '11-3-2012', '3-12-2019', '3-9-2014', '21-6-2017', '24-2-2013', '17-6-2012', '25-3-2018', '14-4-2013', '16-7-2022', '17-7-2021', '11-10-2021', '29-3-2013', '24-12-2022', '8-11-2014', '12-9-2020', '18-11-2012', '21-12-2015', '20-3-2014', '22-11-2015', '6-2-2022', '26-11-2021', '20-11-2015', '6-9-2015', '1-4-2017', '2-6-2021', '22-1-2016', '9-3-2018', '7-2-2015', '29-12-2017', '19-6-2012', '17-1-2022', '25-9-2013', '19-5-2019', '16-12-2019', '3-6-2017', '6-3-2015', '2-7-2012', '26-9-2017', '6-5-2016', '2-2-2019', '11-6-2016', '20-7-2017', '8-10-2020', '3-2-2018', '26-11-2014', '6-10-2014', '25-2-2020', '27-3-2013', '14-4-2019', '6-5-2019', '24-3-2020', '14-11-2015', '8-6-2019', '29-3-2022', '8-10-2016', '9-12-2014', '13-6-2013', '16-6-2020', '11-11-2017', '11-12-2015', '10-8-2019', '11-10-2021', '18-3-2012', '4-10-2013', '20-3-2012', '25-1-2012', '6-12-2015', '2-11-2022', '24-7-2022', '7-3-2019', '25-11-2013', '4-6-2020', '5-10-2021', '4-12-2018', '28-5-2021', '9-2-2013', '20-3-2019', '15-4-2019', '24-1-2022', '8-1-2022', '11-4-2017', '14-9-2012', '30-6-2020', '14-9-2019', '15-2-2022', '22-4-2018', '19-8-2017', '10-6-2013', '1-5-2018', '9-1-2013', '8-6-2016', '20-8-2020', '9-11-2022', '16-5-2014', '1-2-2015', '3-11-2021', '16-12-2017', '14-7-2017', '23-9-2012', '12-4-2015', '22-6-2016', '28-4-2013', '1-10-2016', '24-6-2014', '14-3-2019', '13-2-2022', '18-8-2022', '7-3-2013', '24-3-2019', '3-11-2012', '13-4-2020', '30-11-2018', '22-9-2015', '18-7-2022', '13-11-2022', '9-4-2016', '23-8-2017', '22-1-2016', '5-10-2017', '23-7-2018', '8-7-2018', '19-12-2018', '28-12-2013', '25-7-2013', '16-3-2016', '10-6-2018', '23-1-2018', '12-2-2012', '10-5-2019', '29-12-2013', '5-7-2014', '1-1-2022', '27-2-2014', '5-9-2019', '12-8-2016', '30-9-2018', '29-7-2014', '11-5-2019', '9-2-2012', '15-10-2017', '10-8-2022', '20-10-2019', '24-11-2018', '2-12-2015', '15-11-2013', '4-7-2022', '9-5-2020', '28-6-2022', '28-2-2016', '14-11-2015', '24-1-2016', '23-5-2019', '21-10-2017', '24-7-2015', '29-12-2019', '4-11-2019', '13-2-2019', '27-11-2020', '6-9-2022', '5-4-2022', '22-4-2020', '18-7-2019', '10-9-2015', '3-11-2012', '27-1-2022', '28-12-2021', '12-10-2015', '22-1-2016', '9-8-2015', '29-3-2020', '24-12-2015', '22-5-2020', '25-8-2014', '1-10-2015', '1-3-2015', '23-2-2021', '27-1-2017', '20-10-2012', '28-12-2015', '30-3-2016', '18-8-2014', '8-4-2015', '9-10-2017', '17-12-2018', '26-9-2017', '5-1-2012', '22-3-2016', '10-11-2015', '21-11-2014', '4-6-2019', '11-3-2019', '11-5-2019', '8-11-2015', '17-4-2015', '13-2-2017', '23-1-2019', '17-1-2020', '27-11-2015', '23-1-2013', '10-5-2012', '23-11-2013', '8-4-2018', '13-3-2022', '9-4-2014', '27-6-2022', '30-6-2022', '9-5-2019', '23-6-2019', '13-7-2017', '6-1-2014', '13-11-2021', '10-1-2013', '10-12-2021', '25-11-2019', '13-5-2022', '24-6-2018', '8-8-2020', '10-5-2013', '24-12-2020', '28-6-2014', '18-10-2022', '1-7-2015', '1-3-2013', '30-1-2012', '19-11-2022', '13-3-2022', '10-2-2018', '29-4-2022', '16-7-2012', '16-12-2013', '21-12-2014', '4-3-2012', '15-12-2017', '7-9-2016', '26-6-2016', '1-12-2012', '10-6-2020', '19-10-2015', '19-9-2022', '25-7-2016', '7-3-2019', '11-7-2021', '24-5-2014', '24-5-2022', '30-2-2018', '1-1-2021', '4-1-2017', '19-11-2014', '13-5-2022', '26-2-2019', '14-11-2015', '12-3-2012', '27-3-2015', '15-5-2018', '3-3-2019', '28-6-2019', '23-10-2016', '7-1-2020', '24-7-2014', '3-8-2014', '6-12-2019', '27-12-2016', '9-7-2014', '19-3-2017', '11-11-2018', '22-11-2014', '6-12-2014', '9-7-2012', '15-3-2021', '6-8-2022', '9-2-2020', '11-7-2018', '27-7-2021', '23-1-2012', '10-3-2019', '2-12-2017', '28-11-2022', '16-1-2022', '15-10-2014', '8-7-2013', '12-11-2017', '3-7-2020', '2-5-2016', '20-1-2013', '28-3-2013', '13-4-2019', '13-7-2015', '24-9-2016', '11-2-2012', '16-11-2015', '20-5-2022', '23-11-2013', '13-11-2016', '3-5-2015', '5-1-2021', '1-9-2014', '8-6-2015', '4-6-2014', '3-3-2017', '18-11-2016', '12-4-2013', '3-7-2017', '26-5-2012', '4-2-2021', '29-12-2021', '22-10-2013', '7-2-2016', '9-9-2019', '15-1-2019', '19-7-2015', '29-12-2019', '30-7-2016', '11-1-2017', '29-7-2018', '18-5-2015', '20-6-2014', '16-2-2018', '24-9-2019', '2-6-2016', '4-6-2014', '13-6-2013', '13-3-2013', '4-7-2018', '25-10-2012', '30-6-2021', '26-12-2015', '16-5-2021', '17-7-2016', '27-7-2019', '1-4-2016', '11-4-2012', '7-10-2022', '9-6-2012', '16-5-2022', '11-6-2022', '5-3-2017', '8-7-2014', '28-1-2019', '29-12-2015', '5-10-2014', '13-4-2018', '2-9-2018', '3-9-2014', '27-6-2020', '21-10-2018', '11-12-2013', '23-5-2012', '9-5-2012', '25-8-2016', '14-6-2021', '4-2-2015', '13-8-2022', '15-3-2019', '19-3-2016', '5-8-2022', '22-6-2014', '3-4-2018', '6-7-2021', '7-9-2021', '4-10-2013', '17-4-2014', '13-8-2013', '27-5-2014', '28-3-2022', '10-11-2020', '13-11-2017', '25-9-2012', '25-4-2017', '28-4-2015', '7-10-2018', '11-8-2018', '8-5-2016', '30-12-2019', '2-1-2018', '29-8-2016', '27-7-2015', '25-1-2018', '4-1-2013', '17-12-2017', '27-6-2020', '26-7-2022', '13-8-2014', '9-12-2020', '15-7-2013', '13-9-2021', '10-11-2021', '6-2-2013', '10-11-2012', '19-10-2014', '9-5-2012', '12-4-2012', '10-7-2018', '22-5-2012', '10-6-2017', '11-11-2013', '23-4-2018', '13-10-2021', '26-12-2015', '25-8-2012', '23-6-2017', '30-5-2022', '11-10-2021', '1-6-2020', '14-12-2020', '16-9-2019', '6-10-2017', '7-1-2018', '23-2-2021', '12-3-2022', '26-1-2016', '11-11-2018', '6-11-2013', '3-4-2013', '28-1-2018', '7-4-2018', '23-5-2019', '27-9-2016', '16-3-2012', '18-9-2019', '8-6-2015', '11-5-2015', '2-12-2013', '15-2-2013', '30-7-2021', '28-7-2022', '10-7-2022', '2-1-2013', '7-3-2013', '19-3-2015', '2-6-2022', '29-10-2012', '22-3-2016', '24-6-2019', '18-12-2021', '25-8-2021', '1-4-2022', '14-12-2022', '30-9-2020', '22-1-2020', '3-3-2022', '6-2-2017', '24-11-2016', '10-9-2014', '13-6-2014', '13-3-2021', '13-3-2021', '26-2-2015', '13-1-2018', '30-1-2014', '15-3-2016', '16-5-2017', '13-7-2015', '28-1-2016', '2-2-2021', '19-1-2017', '26-8-2015', '1-6-2021', '17-9-2017', '5-2-2020', '5-1-2019', '7-3-2021', '14-4-2019', '23-3-2018', '18-4-2015', '21-6-2015', '22-1-2022', '23-10-2014', '27-5-2013', '10-10-2016', '11-12-2017', '24-5-2021', '13-3-2019', '20-5-2018', '1-1-2013', '6-9-2012', '10-10-2022', '18-3-2017', '29-11-2019', '10-7-2015', '2-4-2012', '3-8-2016', '15-7-2019', '3-3-2016', '5-8-2022', '3-3-2017', '14-1-2015', '7-2-2018', '6-6-2018', '24-1-2018', '2-4-2014', '12-9-2020', '26-10-2015', '8-3-2021', '15-12-2020', '14-3-2015', '4-3-2016', '25-7-2013', '24-2-2016', '13-3-2013', '15-12-2022', '19-5-2017', '14-12-2019', '22-6-2013', '25-5-2015', '18-9-2019', '6-11-2018', '16-2-2015', '27-10-2018', '18-2-2015', '25-10-2022', '5-9-2012', '27-4-2012', '12-9-2013', '10-6-2020', '8-6-2012', '1-2-2015', '23-10-2013', '16-6-2020', '24-10-2017', '11-1-2015', '28-9-2021', '21-6-2022', '12-3-2014', '8-6-2014', '20-8-2016', '21-8-2015', '17-7-2013', '11-8-2022', '11-1-2013', '29-1-2015', '27-3-2013', '26-5-2022', '22-12-2017', '26-2-2022', '5-12-2013', '16-3-2013', '5-2-2019', '28-7-2021', '4-12-2014', '1-1-2018', '23-8-2015', '14-11-2016', '24-2-2017', '5-12-2014', '13-8-2012', '16-8-2014', '11-11-2013', '16-8-2013', '9-1-2021', '15-3-2020', '21-9-2016', '29-10-2020', '23-6-2020', '15-2-2015', '25-2-2022', '26-10-2017', '27-7-2021', '16-4-2019', '4-10-2018', '27-9-2020', '7-9-2018', '19-11-2014', '17-6-2021', '28-1-2021', '5-11-2012', '6-7-2022', '23-5-2020', '22-2-2022', '12-12-2015', '9-12-2019', '30-4-2017', '7-3-2018', '29-9-2020', '2-2-2012', '15-1-2012', '24-10-2017', '27-1-2015', '21-9-2017', '2-9-2017', '10-3-2021', '24-8-2012', '15-12-2021', '15-7-2017', '10-9-2014', '29-12-2013', '9-3-2015', '27-5-2022', '4-10-2020', '17-6-2015', '25-6-2020', '30-10-2013', '23-9-2014', '14-12-2013', '14-5-2013', '23-12-2021', '13-5-2014', '24-3-2012', '1-6-2019', '23-2-2018', '23-1-2013', '26-1-2016', '12-12-2016', '9-5-2016', '19-3-2020', '14-10-2015', '13-7-2022', '6-5-2014', '12-4-2013', '3-1-2019', '7-9-2016', '21-2-2018', '29-12-2020', '16-1-2021', '8-4-2021', '21-7-2021', '1-8-2018', '23-11-2013', '2-8-2014', '28-3-2017', '20-1-2017', '30-6-2022', '17-1-2013', '6-6-2013', '9-2-2014', '8-10-2013', '10-4-2022', '21-11-2016', '28-7-2022', '14-7-2012', '26-9-2020', '30-5-2015', '7-4-2013', '19-8-2021', '3-11-2018', '13-7-2018', '9-4-2019', '27-7-2020', '4-11-2012', '22-12-2016', '24-2-2015', '30-4-2018', '30-5-2018', '1-10-2020', '4-6-2021', '4-9-2013', '26-7-2019', '3-10-2014', '8-6-2015', '4-8-2021', '7-3-2019', '12-11-2015', '27-5-2020', '29-3-2012', '16-6-2013', '24-4-2019', '5-4-2013', '7-6-2021', '24-2-2018', '7-2-2021', '20-3-2015', '14-4-2017', '2-8-2013', '29-11-2019', '22-12-2022', '19-6-2019', '2-9-2013', '12-1-2021', '17-5-2020', '19-3-2020', '28-4-2019', '5-4-2017', '24-2-2019', '29-2-2014', '29-3-2022', '29-3-2016', '25-6-2012', '4-8-2019', '17-2-2021', '11-4-2022', '18-1-2016', '5-4-2013', '3-8-2021', '16-8-2018', '25-9-2012', '7-2-2021', '25-4-2022', '17-4-2018', '14-6-2014', '14-5-2013', '27-10-2020', '12-8-2022', '6-6-2016', '19-5-2016', '3-12-2014', '9-11-2022', '27-2-2022', '1-5-2018', '29-2-2014', '7-5-2021', '8-9-2020', '22-6-2013', '19-12-2019', '2-3-2022', '14-3-2012', '8-6-2017', '13-12-2017', '25-12-2014', '17-7-2012', '23-11-2017', '24-4-2018', '13-5-2015', '8-5-2017', '16-1-2014', '13-6-2020', '27-9-2019', '2-9-2022', '21-10-2017', '1-3-2022', '7-5-2016', '10-3-2016', '26-7-2022', '19-9-2017', '15-8-2018', '19-10-2021', '1-1-2021', '10-8-2020', '17-12-2016', '6-8-2017', '24-11-2018', '30-3-2012', '7-1-2014', '15-4-2016', '18-10-2015', '15-1-2018', '28-9-2013', '8-3-2012', '15-6-2013', '5-7-2016', '6-7-2012', '12-2-2021', '22-4-2022', '2-2-2019', '22-1-2016', '11-3-2014', '7-10-2021', '20-8-2015', '26-12-2019', '12-2-2022', '23-12-2016', '23-2-2016', '27-1-2012', '22-10-2019', '22-12-2020', '26-5-2016', '2-3-2016', '10-7-2022', '9-8-2012', '8-6-2016', '16-8-2014', '3-8-2022', '19-7-2020', '27-7-2022', '17-9-2013', '25-11-2019', '23-3-2021', '9-3-2014', '23-12-2016', '28-12-2022', '19-2-2021', '20-7-2020', '5-1-2018', '3-2-2016', '26-4-2016', '2-3-2017', '23-4-2016', '26-10-2018', '20-5-2016', '7-9-2015', '17-5-2012', '6-7-2018', '5-1-2014', '13-12-2020', '22-1-2015', '1-8-2019', '6-8-2017', '22-4-2018', '30-12-2021', '29-6-2017', '17-10-2012', '18-12-2020', '26-12-2015', '6-6-2016', '13-1-2016', '9-5-2015', '17-5-2018', '3-7-2014', '21-1-2016', '7-10-2012', '26-1-2014', '20-9-2020', '20-1-2012', '13-4-2014', '5-6-2014', '14-7-2018', '27-9-2016', '13-11-2016']

categories = ['Restauracja', 'Kawiarnia', 'Bar', 'Pub', 'Catering', 'Sklep spozywczy', 'Delikates', 'Lodziarnia', 'Pizzeria', 'Fast food', 'Street food', 'Sklep z alkoholem', 'Uslugi cateringowe', 'Hotel lub pensjonat', 'Sklep z przyprawami i produktami kulinarnymi', 'Importer i dystrybutor zywnosci', 'Szkolka kulinarne', 'Stolowka i jalodajnie', 'Bar mleczny', 'Bar sushi', 'Kebab', 'Bar szybkiej obslugi']


print('------- inserty pracownicy --------')
for i in range(127):
  numer = numery[randint(0,len(numery) - 1)]
  numery.remove(numer)
  print(f"INSERT INTO pracownicy VALUES ('{i + 1}','{names[randint(0,len(names)-1)]}','{surnames[randint(0,len(surnames) - 1)]}', to_date('{data_zatrudnienia[randint(0,len(data_zatrudnienia) - 1)]}','DD-MM-YYYY'),{numer},{randint(1,40)},{randint(1,20)});")

print('------- inserty klienci --------')

for i in range(659):
  numer = numery[randint(0,len(numery) - 1)]
  numery.remove(numer)
  print(f"INSERT INTO klienci VALUES ('{i + 1}','{names[randint(0,len(names)-1)]}','{surnames[randint(0,len(surnames) - 1)]}',{numer},'{categories[randint(0,len(categories) - 1)]}',{randint(1,40)});")



