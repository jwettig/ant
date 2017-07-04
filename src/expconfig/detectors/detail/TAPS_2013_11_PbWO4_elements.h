#include "detectors/TAPS.h"
const std::vector<ant::expconfig::detector::TAPS_2013_11::PbWO4_Element_t>
ant::expconfig::detector::TAPS_2013_11::PbWO4_elements_init = {
  // element, {xy}, TDC, QDCH, QDCL, {neigbours}
  {  0, { -3.849,   4.333}, 29224, 29000, 29001, {368,366,375,376,1,3,2}},
  {  1, { -6.543,   4.333}, 29227, 29006, 29007, {0,375,376,4,6,8,3,2}},
  {  2, { -3.849,   1.667}, 29225, 29002, 29003, {368,0,1,3,74,73}},
  {  3, { -6.543,   1.667}, 29226, 29004, 29005, {2,0,1,6,8,10,74,73}},
  {  4, { -9.045,   7.333}, 29228, 29008, 29009, {376,374,379,5,7,6,1}},
  {  5, {-11.739,   7.333}, 29231, 29014, 29015, {4,379,12,13,7,6}},
  {  6, { -9.045,   4.667}, 29229, 29010, 29011, {1,376,4,5,7,9,8,3}},
  {  7, {-11.739,   4.667}, 29230, 29012, 29013, {6,4,5,12,13,9,8}},
  {  8, { -9.045,   1.333}, 29232, 29016, 29017, {3,1,6,7,9,11,10,74}},
  {  9, {-11.739,   1.333}, 29235, 29022, 29023, {8,6,7,13,14,11,10}},
  { 10, { -9.045,  -1.333}, 29233, 29018, 29019, {74,3,8,9,11,78,77,76}},
  { 11, {-11.739,  -1.333}, 29234, 29020, 29021, {10,8,9,13,14,78,77}},
  { 73, { -3.849,  -1.667}, 29236, 29024, 29025, {2,3,74,76,75,147}},
  { 74, { -6.543,  -1.667}, 29239, 29030, 29031, {73,2,3,8,10,77,76,75}},
  { 75, { -3.849,  -4.333}, 29237, 29026, 29027, {147,73,74,76,82,81,149}},
  { 76, { -6.543,  -4.333}, 29238, 29028, 29029, {75,73,74,10,77,79,82,81}},
  { 77, { -9.045,  -4.667}, 29240, 29032, 29033, {76,74,10,11,78,80,79,82}},
  { 78, {-11.739,  -4.667}, 29243, 29038, 29039, {77,10,11,14,85,80,79}},
  { 79, { -9.045,  -7.333}, 29241, 29034, 29035, {82,76,77,78,80,86,84}},
  { 80, {-11.739,  -7.333}, 29242, 29036, 29037, {79,77,78,14,85,86}},
  { 81, { -3.849,  -7.667}, 29244, 29040, 29041, {149,147,75,76,82,84,83,151}},
  { 82, { -6.543,  -7.667}, 29247, 29046, 29047, {81,75,76,77,79,86,84,83}},
  { 83, { -3.849, -10.333}, 29245, 29042, 29043, {151,149,81,82,84,87,153}},
  { 84, { -6.543, -10.333}, 29246, 29044, 29045, {83,81,82,79,86,87}},
  {146, {  1.347,  -4.667}, 29248, 29048, 29049, {222,220,147,149,148,155}},
  {147, { -1.347,  -4.667}, 29251, 29054, 29055, {146,73,75,81,149,148}},
  {148, {  1.347,  -7.333}, 29249, 29050, 29051, {155,222,146,147,149,151,150,157}},
  {149, { -1.347,  -7.333}, 29250, 29052, 29053, {148,146,147,75,81,83,151,150}},
  {150, {  1.347, -10.667}, 29252, 29056, 29057, {157,155,148,149,151,153,152,159}},
  {151, { -1.347, -10.667}, 29255, 29062, 29063, {150,148,149,81,83,87,153,152}},
  {152, {  1.347, -13.333}, 29253, 29058, 29059, {159,157,150,151,153,158}},
  {153, { -1.347, -13.333}, 29254, 29060, 29061, {152,150,151,83,87,158}},
  {154, {  6.543,  -7.667}, 29256, 29064, 29065, {226,224,221,222,155,157,156,160}},
  {155, {  3.849,  -7.667}, 29259, 29070, 29071, {154,221,222,146,148,150,157,156}},
  {156, {  6.543, -10.333}, 29257, 29066, 29067, {160,226,154,155,157,159}},
  {157, {  3.849, -10.333}, 29258, 29068, 29069, {156,154,155,148,150,152,159}},
  {219, {  6.543,  -1.667}, 29260, 29072, 29073, {230,228,294,295,220,222,221,224}},
  {220, {  3.849,  -1.667}, 29263, 29078, 29079, {219,294,295,146,222,221}},
  {221, {  6.543,  -4.333}, 29261, 29074, 29075, {224,230,219,220,222,155,154,226}},
  {222, {  3.849,  -4.333}, 29262, 29076, 29077, {221,219,220,146,148,155,154}},
  {223, { 11.739,  -4.667}, 29264, 29080, 29081, {232,229,230,224,226,225,231}},
  {224, {  9.045,  -4.667}, 29267, 29086, 29087, {223,229,230,219,221,154,226,225}},
  {225, { 11.739,  -7.333}, 29265, 29082, 29083, {231,232,223,224,226,160,231}},
  {226, {  9.045,  -7.333}, 29266, 29084, 29085, {225,223,224,221,154,156,160}},
  {227, { 11.739,   1.333}, 29268, 29088, 29089, {233,298,299,228,230,229,232}},
  {228, {  9.045,   1.333}, 29271, 29094, 29095, {227,298,299,292,294,219,230,229}},
  {229, { 11.739,  -1.333}, 29269, 29090, 29091, {232,233,227,228,230,224,223}},
  {230, {  9.045,  -1.333}, 29270, 29092, 29093, {229,227,228,294,219,221,224,223}},
  {292, {  6.543,   4.333}, 29272, 29096, 29097, {299,297,302,303,293,295,294,228}},
  {293, {  3.849,   4.333}, 29275, 29102, 29103, {292,302,303,365,367,295,294}},
  {294, {  6.543,   1.667}, 29273, 29098, 29099, {228,299,292,293,295,220,219,230}},
  {295, {  3.849,   1.667}, 29274, 29100, 29101, {294,292,293,367,220,219,294}},
  {296, { 11.739,   7.333}, 29276, 29104, 29105, {304,305,297,299,298,233}},
  {297, {  9.045,   7.333}, 29279, 29110, 29111, {296,305,300,302,292,299,298}},
  {298, { 11.739,   4.667}, 29277, 29106, 29107, {233,304,296,297,299,228,227}},
  {299, {  9.045,   4.667}, 29278, 29108, 29109, {298,296,297,302,292,294,228,227}},
  {300, {  6.543,  10.333}, 29280, 29112, 29113, {305,306,301,303,302,297}},
  {301, {  3.849,  10.333}, 29283, 29118, 29119, {300,306,369,371,365,303,302}},
  {302, {  6.543,   7.667}, 29281, 29114, 29115, {297,305,300,301,303,293,292,299}},
  {303, {  3.849,   7.667}, 29282, 29116, 29117, {302,300,301,371,365,367,293,292}},
  {365, {  1.347,   7.333}, 29284, 29120, 29121, {303,301,371,372,366,368,367,293}},
  {366, { -1.347,   7.333}, 29287, 29126, 29127, {365,371,372,373,375,0,368,367}},
  {367, {  1.347,   4.667}, 29285, 29122, 29123, {293,303,365,366,368,295}},
  {368, { -1.347,   4.667}, 29286, 29124, 29125, {367,365,366,375,0,2}},
  {369, {  1.347,  13.333}, 29288, 29128, 29129, {306,377,370,372,371,301}},
  {370, { -1.347,  13.333}, 29291, 29134, 29135, {369,377,378,373,372,371}},
  {371, {  1.347,  10.667}, 29289, 29130, 29131, {301,306,369,370,372,366,365,303}},
  {372, { -1.347,  10.667}, 29290, 29132, 29133, {371,369,370,378,373,375,366,365}},
  {373, { -3.849,  10.333}, 29292, 29136, 29137, {372,370,378,374,376,375,366}},
  {374, { -6.543,  10.333}, 29295, 29142, 29143, {373,378,379,4,376,375}},
  {375, { -3.849,   7.667}, 29293, 29138, 29139, {366,372,373,374,376,1,0,368}},
  {376, { -6.543,   7.667}, 29294, 29140, 29141, {375,373,374,379,4,6,1,0}},
};