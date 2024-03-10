
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

/// This is top function.
/// Latency=6278, interval=6278
/// DSP=140, BRAM=0
void test_gesummv(
  float v0,
  float v1,
  float v2[250][250],
  float v3[250][250],
  float v4[250],
  float v5[250],
  float v6[250]
) {	// L6, [0,6278)
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface s_axilite port=v0 bundle=ctrl
  #pragma HLS interface s_axilite port=v1 bundle=ctrl
  #pragma HLS array_partition variable=v2 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v2 cyclic factor=2 dim=2
  #pragma HLS resource variable=v2 core=ram_t2p_bram

  #pragma HLS array_partition variable=v3 cyclic factor=10 dim=1
  #pragma HLS array_partition variable=v3 cyclic factor=2 dim=2
  #pragma HLS resource variable=v3 core=ram_t2p_bram

  #pragma HLS array_partition variable=v4 cyclic factor=10 dim=1
  #pragma HLS resource variable=v4 core=ram_t2p_bram

  #pragma HLS array_partition variable=v5 cyclic factor=2 dim=1
  #pragma HLS resource variable=v5 core=ram_t2p_bram

  #pragma HLS array_partition variable=v6 cyclic factor=10 dim=1
  #pragma HLS resource variable=v6 core=ram_t2p_bram

  for (int v7 = 0; v7 < 125; v7 += 1) {	// L7, [0,6276), iterCycle=26, II=2
    for (int v8 = 0; v8 < 25; v8 += 1) {	// L8, [0,76), iterCycle=26, II=2
      #pragma HLS pipeline II=2
      float v9 = v2[(v8 * 10)][(v7 * 2)];	// L9, [0,2)
      float v10 = v5[(v7 * 2)];	// L10, [0,2)
      float v11 = v9 * v10;	// L11, [2,6)
      float v12 = v3[(v8 * 10)][(v7 * 2)];	// L12, [0,2)
      float v13 = v12 * v10;	// L13, [2,6)
      float v14 = v6[(v8 * 10)];	// L14, [4,6)
      float v15 = v14 + v13;	// L15, [6,11)
      float v16 = v2[((v8 * 10) + 1)][(v7 * 2)];	// L16, [0,2)
      float v17 = v16 * v10;	// L17, [2,6)
      float v18 = v3[((v8 * 10) + 1)][(v7 * 2)];	// L18, [0,2)
      float v19 = v18 * v10;	// L19, [2,6)
      float v20 = v6[((v8 * 10) + 1)];	// L20, [4,6)
      float v21 = v20 + v19;	// L21, [6,11)
      float v22 = v2[((v8 * 10) + 2)][(v7 * 2)];	// L22, [0,2)
      float v23 = v22 * v10;	// L23, [2,6)
      float v24 = v3[((v8 * 10) + 2)][(v7 * 2)];	// L24, [0,2)
      float v25 = v24 * v10;	// L25, [2,6)
      float v26 = v6[((v8 * 10) + 2)];	// L26, [4,6)
      float v27 = v26 + v25;	// L27, [6,11)
      float v28 = v2[((v8 * 10) + 3)][(v7 * 2)];	// L28, [0,2)
      float v29 = v28 * v10;	// L29, [2,6)
      float v30 = v3[((v8 * 10) + 3)][(v7 * 2)];	// L30, [0,2)
      float v31 = v30 * v10;	// L31, [2,6)
      float v32 = v6[((v8 * 10) + 3)];	// L32, [4,6)
      float v33 = v32 + v31;	// L33, [6,11)
      float v34 = v2[((v8 * 10) + 4)][(v7 * 2)];	// L34, [0,2)
      float v35 = v34 * v10;	// L35, [2,6)
      float v36 = v3[((v8 * 10) + 4)][(v7 * 2)];	// L36, [0,2)
      float v37 = v36 * v10;	// L37, [2,6)
      float v38 = v6[((v8 * 10) + 4)];	// L38, [4,6)
      float v39 = v38 + v37;	// L39, [6,11)
      float v40 = v2[((v8 * 10) + 5)][(v7 * 2)];	// L40, [0,2)
      float v41 = v40 * v10;	// L41, [2,6)
      float v42 = v3[((v8 * 10) + 5)][(v7 * 2)];	// L42, [0,2)
      float v43 = v42 * v10;	// L43, [2,6)
      float v44 = v6[((v8 * 10) + 5)];	// L44, [4,6)
      float v45 = v44 + v43;	// L45, [6,11)
      float v46 = v2[((v8 * 10) + 6)][(v7 * 2)];	// L46, [0,2)
      float v47 = v46 * v10;	// L47, [2,6)
      float v48 = v3[((v8 * 10) + 6)][(v7 * 2)];	// L48, [0,2)
      float v49 = v48 * v10;	// L49, [2,6)
      float v50 = v6[((v8 * 10) + 6)];	// L50, [4,6)
      float v51 = v50 + v49;	// L51, [6,11)
      float v52 = v2[((v8 * 10) + 7)][(v7 * 2)];	// L52, [0,2)
      float v53 = v52 * v10;	// L53, [2,6)
      float v54 = v3[((v8 * 10) + 7)][(v7 * 2)];	// L54, [0,2)
      float v55 = v54 * v10;	// L55, [2,6)
      float v56 = v6[((v8 * 10) + 7)];	// L56, [4,6)
      float v57 = v56 + v55;	// L57, [6,11)
      float v58 = v2[((v8 * 10) + 8)][(v7 * 2)];	// L58, [0,2)
      float v59 = v58 * v10;	// L59, [2,6)
      float v60 = v3[((v8 * 10) + 8)][(v7 * 2)];	// L60, [0,2)
      float v61 = v60 * v10;	// L61, [2,6)
      float v62 = v6[((v8 * 10) + 8)];	// L62, [4,6)
      float v63 = v62 + v61;	// L63, [6,11)
      float v64 = v2[((v8 * 10) + 9)][(v7 * 2)];	// L64, [0,2)
      float v65 = v64 * v10;	// L65, [2,6)
      float v66 = v3[((v8 * 10) + 9)][(v7 * 2)];	// L66, [0,2)
      float v67 = v66 * v10;	// L67, [2,6)
      float v68 = v6[((v8 * 10) + 9)];	// L68, [4,6)
      float v69 = v68 + v67;	// L69, [6,11)
      float v70 = v2[(v8 * 10)][((v7 * 2) + 1)];	// L70, [0,2)
      float v71 = v5[((v7 * 2) + 1)];	// L71, [0,2)
      float v72 = v70 * v71;	// L72, [2,6)
      float v73 = v11 + v72;	// L73, [6,11)
      float v74 = v4[(v8 * 10)];	// L74, [9,11)
      float v75 = v74 + v73;	// L75, [11,16)
      v4[(v8 * 10)] = v75;	// L76, [25,26)
      float v76 = v3[(v8 * 10)][((v7 * 2) + 1)];	// L77, [5,7)
      float v77 = v76 * v71;	// L78, [7,11)
      float v78 = v15 + v77;	// L79, [11,16)
      float v79 = v0 * v75;	// L80, [16,20)
      float v80 = v1 * v78;	// L81, [16,20)
      float v81 = v79 + v80;	// L82, [20,25)
      float v82 = (((v7 * -2) + 248) == 0) ? v81 : v15;	// L83, [25,25)
      v6[(v8 * 10)] = v82;	// L84, [25,26)
      float v83 = v2[((v8 * 10) + 1)][((v7 * 2) + 1)];	// L85, [0,2)
      float v84 = v83 * v71;	// L86, [2,6)
      float v85 = v17 + v84;	// L87, [6,11)
      float v86 = v4[((v8 * 10) + 1)];	// L88, [9,11)
      float v87 = v86 + v85;	// L89, [11,16)
      v4[((v8 * 10) + 1)] = v87;	// L90, [25,26)
      float v88 = v3[((v8 * 10) + 1)][((v7 * 2) + 1)];	// L91, [5,7)
      float v89 = v88 * v71;	// L92, [7,11)
      float v90 = v21 + v89;	// L93, [11,16)
      float v91 = v0 * v87;	// L94, [16,20)
      float v92 = v1 * v90;	// L95, [16,20)
      float v93 = v91 + v92;	// L96, [20,25)
      float v94 = (((v7 * -2) + 248) == 0) ? v93 : v21;	// L97, [25,25)
      v6[((v8 * 10) + 1)] = v94;	// L98, [25,26)
      float v95 = v2[((v8 * 10) + 2)][((v7 * 2) + 1)];	// L99, [0,2)
      float v96 = v95 * v71;	// L100, [2,6)
      float v97 = v23 + v96;	// L101, [6,11)
      float v98 = v4[((v8 * 10) + 2)];	// L102, [9,11)
      float v99 = v98 + v97;	// L103, [11,16)
      v4[((v8 * 10) + 2)] = v99;	// L104, [25,26)
      float v100 = v3[((v8 * 10) + 2)][((v7 * 2) + 1)];	// L105, [5,7)
      float v101 = v100 * v71;	// L106, [7,11)
      float v102 = v27 + v101;	// L107, [11,16)
      float v103 = v0 * v99;	// L108, [16,20)
      float v104 = v1 * v102;	// L109, [16,20)
      float v105 = v103 + v104;	// L110, [20,25)
      float v106 = (((v7 * -2) + 248) == 0) ? v105 : v27;	// L111, [25,25)
      v6[((v8 * 10) + 2)] = v106;	// L112, [25,26)
      float v107 = v2[((v8 * 10) + 3)][((v7 * 2) + 1)];	// L113, [0,2)
      float v108 = v107 * v71;	// L114, [2,6)
      float v109 = v29 + v108;	// L115, [6,11)
      float v110 = v4[((v8 * 10) + 3)];	// L116, [9,11)
      float v111 = v110 + v109;	// L117, [11,16)
      v4[((v8 * 10) + 3)] = v111;	// L118, [25,26)
      float v112 = v3[((v8 * 10) + 3)][((v7 * 2) + 1)];	// L119, [5,7)
      float v113 = v112 * v71;	// L120, [7,11)
      float v114 = v33 + v113;	// L121, [11,16)
      float v115 = v0 * v111;	// L122, [16,20)
      float v116 = v1 * v114;	// L123, [16,20)
      float v117 = v115 + v116;	// L124, [20,25)
      float v118 = (((v7 * -2) + 248) == 0) ? v117 : v33;	// L125, [25,25)
      v6[((v8 * 10) + 3)] = v118;	// L126, [25,26)
      float v119 = v2[((v8 * 10) + 4)][((v7 * 2) + 1)];	// L127, [0,2)
      float v120 = v119 * v71;	// L128, [2,6)
      float v121 = v35 + v120;	// L129, [6,11)
      float v122 = v4[((v8 * 10) + 4)];	// L130, [9,11)
      float v123 = v122 + v121;	// L131, [11,16)
      v4[((v8 * 10) + 4)] = v123;	// L132, [25,26)
      float v124 = v3[((v8 * 10) + 4)][((v7 * 2) + 1)];	// L133, [5,7)
      float v125 = v124 * v71;	// L134, [7,11)
      float v126 = v39 + v125;	// L135, [11,16)
      float v127 = v0 * v123;	// L136, [16,20)
      float v128 = v1 * v126;	// L137, [16,20)
      float v129 = v127 + v128;	// L138, [20,25)
      float v130 = (((v7 * -2) + 248) == 0) ? v129 : v39;	// L139, [25,25)
      v6[((v8 * 10) + 4)] = v130;	// L140, [25,26)
      float v131 = v2[((v8 * 10) + 5)][((v7 * 2) + 1)];	// L141, [0,2)
      float v132 = v131 * v71;	// L142, [2,6)
      float v133 = v41 + v132;	// L143, [6,11)
      float v134 = v4[((v8 * 10) + 5)];	// L144, [9,11)
      float v135 = v134 + v133;	// L145, [11,16)
      v4[((v8 * 10) + 5)] = v135;	// L146, [25,26)
      float v136 = v3[((v8 * 10) + 5)][((v7 * 2) + 1)];	// L147, [5,7)
      float v137 = v136 * v71;	// L148, [7,11)
      float v138 = v45 + v137;	// L149, [11,16)
      float v139 = v0 * v135;	// L150, [16,20)
      float v140 = v1 * v138;	// L151, [16,20)
      float v141 = v139 + v140;	// L152, [20,25)
      float v142 = (((v7 * -2) + 248) == 0) ? v141 : v45;	// L153, [25,25)
      v6[((v8 * 10) + 5)] = v142;	// L154, [25,26)
      float v143 = v2[((v8 * 10) + 6)][((v7 * 2) + 1)];	// L155, [0,2)
      float v144 = v143 * v71;	// L156, [2,6)
      float v145 = v47 + v144;	// L157, [6,11)
      float v146 = v4[((v8 * 10) + 6)];	// L158, [9,11)
      float v147 = v146 + v145;	// L159, [11,16)
      v4[((v8 * 10) + 6)] = v147;	// L160, [25,26)
      float v148 = v3[((v8 * 10) + 6)][((v7 * 2) + 1)];	// L161, [5,7)
      float v149 = v148 * v71;	// L162, [7,11)
      float v150 = v51 + v149;	// L163, [11,16)
      float v151 = v0 * v147;	// L164, [16,20)
      float v152 = v1 * v150;	// L165, [16,20)
      float v153 = v151 + v152;	// L166, [20,25)
      float v154 = (((v7 * -2) + 248) == 0) ? v153 : v51;	// L167, [25,25)
      v6[((v8 * 10) + 6)] = v154;	// L168, [25,26)
      float v155 = v2[((v8 * 10) + 7)][((v7 * 2) + 1)];	// L169, [0,2)
      float v156 = v155 * v71;	// L170, [2,6)
      float v157 = v53 + v156;	// L171, [6,11)
      float v158 = v4[((v8 * 10) + 7)];	// L172, [9,11)
      float v159 = v158 + v157;	// L173, [11,16)
      v4[((v8 * 10) + 7)] = v159;	// L174, [25,26)
      float v160 = v3[((v8 * 10) + 7)][((v7 * 2) + 1)];	// L175, [5,7)
      float v161 = v160 * v71;	// L176, [7,11)
      float v162 = v57 + v161;	// L177, [11,16)
      float v163 = v0 * v159;	// L178, [16,20)
      float v164 = v1 * v162;	// L179, [16,20)
      float v165 = v163 + v164;	// L180, [20,25)
      float v166 = (((v7 * -2) + 248) == 0) ? v165 : v57;	// L181, [25,25)
      v6[((v8 * 10) + 7)] = v166;	// L182, [25,26)
      float v167 = v2[((v8 * 10) + 8)][((v7 * 2) + 1)];	// L183, [0,2)
      float v168 = v167 * v71;	// L184, [2,6)
      float v169 = v59 + v168;	// L185, [6,11)
      float v170 = v4[((v8 * 10) + 8)];	// L186, [9,11)
      float v171 = v170 + v169;	// L187, [11,16)
      v4[((v8 * 10) + 8)] = v171;	// L188, [25,26)
      float v172 = v3[((v8 * 10) + 8)][((v7 * 2) + 1)];	// L189, [5,7)
      float v173 = v172 * v71;	// L190, [7,11)
      float v174 = v63 + v173;	// L191, [11,16)
      float v175 = v0 * v171;	// L192, [16,20)
      float v176 = v1 * v174;	// L193, [16,20)
      float v177 = v175 + v176;	// L194, [20,25)
      float v178 = (((v7 * -2) + 248) == 0) ? v177 : v63;	// L195, [25,25)
      v6[((v8 * 10) + 8)] = v178;	// L196, [25,26)
      float v179 = v2[((v8 * 10) + 9)][((v7 * 2) + 1)];	// L197, [0,2)
      float v180 = v179 * v71;	// L198, [2,6)
      float v181 = v65 + v180;	// L199, [6,11)
      float v182 = v4[((v8 * 10) + 9)];	// L200, [9,11)
      float v183 = v182 + v181;	// L201, [11,16)
      v4[((v8 * 10) + 9)] = v183;	// L202, [25,26)
      float v184 = v3[((v8 * 10) + 9)][((v7 * 2) + 1)];	// L203, [5,7)
      float v185 = v184 * v71;	// L204, [7,11)
      float v186 = v69 + v185;	// L205, [11,16)
      float v187 = v0 * v183;	// L206, [16,20)
      float v188 = v1 * v186;	// L207, [16,20)
      float v189 = v187 + v188;	// L208, [20,25)
      float v190 = (((v7 * -2) + 248) == 0) ? v189 : v69;	// L209, [25,25)
      v6[((v8 * 10) + 9)] = v190;	// L210, [25,26)
    }
  }
}

