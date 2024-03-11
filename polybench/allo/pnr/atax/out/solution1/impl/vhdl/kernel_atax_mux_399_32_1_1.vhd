-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1.2 (64-bit)
-- Tool Version Limit: 2022.04
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- ==============================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

entity kernel_atax_mux_399_32_1_1 is
generic (
    ID            :integer := 0;
    NUM_STAGE     :integer := 1;
    din0_WIDTH       :integer := 32;
    din1_WIDTH       :integer := 32;
    din2_WIDTH       :integer := 32;
    din3_WIDTH       :integer := 32;
    din4_WIDTH       :integer := 32;
    din5_WIDTH       :integer := 32;
    din6_WIDTH       :integer := 32;
    din7_WIDTH       :integer := 32;
    din8_WIDTH       :integer := 32;
    din9_WIDTH       :integer := 32;
    din10_WIDTH       :integer := 32;
    din11_WIDTH       :integer := 32;
    din12_WIDTH       :integer := 32;
    din13_WIDTH       :integer := 32;
    din14_WIDTH       :integer := 32;
    din15_WIDTH       :integer := 32;
    din16_WIDTH       :integer := 32;
    din17_WIDTH       :integer := 32;
    din18_WIDTH       :integer := 32;
    din19_WIDTH       :integer := 32;
    din20_WIDTH       :integer := 32;
    din21_WIDTH       :integer := 32;
    din22_WIDTH       :integer := 32;
    din23_WIDTH       :integer := 32;
    din24_WIDTH       :integer := 32;
    din25_WIDTH       :integer := 32;
    din26_WIDTH       :integer := 32;
    din27_WIDTH       :integer := 32;
    din28_WIDTH       :integer := 32;
    din29_WIDTH       :integer := 32;
    din30_WIDTH       :integer := 32;
    din31_WIDTH       :integer := 32;
    din32_WIDTH       :integer := 32;
    din33_WIDTH       :integer := 32;
    din34_WIDTH       :integer := 32;
    din35_WIDTH       :integer := 32;
    din36_WIDTH       :integer := 32;
    din37_WIDTH       :integer := 32;
    din38_WIDTH       :integer := 32;
    din39_WIDTH       :integer := 32;
    dout_WIDTH        :integer := 32);
port (
    din0   :in  std_logic_vector(31 downto 0);
    din1   :in  std_logic_vector(31 downto 0);
    din2   :in  std_logic_vector(31 downto 0);
    din3   :in  std_logic_vector(31 downto 0);
    din4   :in  std_logic_vector(31 downto 0);
    din5   :in  std_logic_vector(31 downto 0);
    din6   :in  std_logic_vector(31 downto 0);
    din7   :in  std_logic_vector(31 downto 0);
    din8   :in  std_logic_vector(31 downto 0);
    din9   :in  std_logic_vector(31 downto 0);
    din10   :in  std_logic_vector(31 downto 0);
    din11   :in  std_logic_vector(31 downto 0);
    din12   :in  std_logic_vector(31 downto 0);
    din13   :in  std_logic_vector(31 downto 0);
    din14   :in  std_logic_vector(31 downto 0);
    din15   :in  std_logic_vector(31 downto 0);
    din16   :in  std_logic_vector(31 downto 0);
    din17   :in  std_logic_vector(31 downto 0);
    din18   :in  std_logic_vector(31 downto 0);
    din19   :in  std_logic_vector(31 downto 0);
    din20   :in  std_logic_vector(31 downto 0);
    din21   :in  std_logic_vector(31 downto 0);
    din22   :in  std_logic_vector(31 downto 0);
    din23   :in  std_logic_vector(31 downto 0);
    din24   :in  std_logic_vector(31 downto 0);
    din25   :in  std_logic_vector(31 downto 0);
    din26   :in  std_logic_vector(31 downto 0);
    din27   :in  std_logic_vector(31 downto 0);
    din28   :in  std_logic_vector(31 downto 0);
    din29   :in  std_logic_vector(31 downto 0);
    din30   :in  std_logic_vector(31 downto 0);
    din31   :in  std_logic_vector(31 downto 0);
    din32   :in  std_logic_vector(31 downto 0);
    din33   :in  std_logic_vector(31 downto 0);
    din34   :in  std_logic_vector(31 downto 0);
    din35   :in  std_logic_vector(31 downto 0);
    din36   :in  std_logic_vector(31 downto 0);
    din37   :in  std_logic_vector(31 downto 0);
    din38   :in  std_logic_vector(31 downto 0);
    din39   :in  std_logic_vector(8 downto 0);
    dout     :out std_logic_vector(31 downto 0));
end entity;

architecture rtl of kernel_atax_mux_399_32_1_1 is
    -- puts internal signals
    signal sel    : std_logic_vector(8 downto 0);
    -- level 1 signals
    signal mux_1_0    : std_logic_vector(31 downto 0);
    signal mux_1_1    : std_logic_vector(31 downto 0);
    signal mux_1_2    : std_logic_vector(31 downto 0);
    signal mux_1_3    : std_logic_vector(31 downto 0);
    signal mux_1_4    : std_logic_vector(31 downto 0);
    signal mux_1_5    : std_logic_vector(31 downto 0);
    signal mux_1_6    : std_logic_vector(31 downto 0);
    signal mux_1_7    : std_logic_vector(31 downto 0);
    signal mux_1_8    : std_logic_vector(31 downto 0);
    signal mux_1_9    : std_logic_vector(31 downto 0);
    signal mux_1_10    : std_logic_vector(31 downto 0);
    signal mux_1_11    : std_logic_vector(31 downto 0);
    signal mux_1_12    : std_logic_vector(31 downto 0);
    signal mux_1_13    : std_logic_vector(31 downto 0);
    signal mux_1_14    : std_logic_vector(31 downto 0);
    signal mux_1_15    : std_logic_vector(31 downto 0);
    signal mux_1_16    : std_logic_vector(31 downto 0);
    signal mux_1_17    : std_logic_vector(31 downto 0);
    signal mux_1_18    : std_logic_vector(31 downto 0);
    signal mux_1_19    : std_logic_vector(31 downto 0);
    -- level 2 signals
    signal mux_2_0    : std_logic_vector(31 downto 0);
    signal mux_2_1    : std_logic_vector(31 downto 0);
    signal mux_2_2    : std_logic_vector(31 downto 0);
    signal mux_2_3    : std_logic_vector(31 downto 0);
    signal mux_2_4    : std_logic_vector(31 downto 0);
    signal mux_2_5    : std_logic_vector(31 downto 0);
    signal mux_2_6    : std_logic_vector(31 downto 0);
    signal mux_2_7    : std_logic_vector(31 downto 0);
    signal mux_2_8    : std_logic_vector(31 downto 0);
    signal mux_2_9    : std_logic_vector(31 downto 0);
    -- level 3 signals
    signal mux_3_0    : std_logic_vector(31 downto 0);
    signal mux_3_1    : std_logic_vector(31 downto 0);
    signal mux_3_2    : std_logic_vector(31 downto 0);
    signal mux_3_3    : std_logic_vector(31 downto 0);
    signal mux_3_4    : std_logic_vector(31 downto 0);
    -- level 4 signals
    signal mux_4_0    : std_logic_vector(31 downto 0);
    signal mux_4_1    : std_logic_vector(31 downto 0);
    signal mux_4_2    : std_logic_vector(31 downto 0);
    -- level 5 signals
    signal mux_5_0    : std_logic_vector(31 downto 0);
    signal mux_5_1    : std_logic_vector(31 downto 0);
    -- level 6 signals
    signal mux_6_0    : std_logic_vector(31 downto 0);
    -- level 7 signals
    signal mux_7_0    : std_logic_vector(31 downto 0);
    -- level 8 signals
    signal mux_8_0    : std_logic_vector(31 downto 0);
    -- level 9 signals
    signal mux_9_0    : std_logic_vector(31 downto 0);
begin

sel <= din39;

-- Generate level 1 logic
mux_1_0 <= din0 when sel(0) = '0' else din1;
mux_1_1 <= din2 when sel(0) = '0' else din3;
mux_1_2 <= din4 when sel(0) = '0' else din5;
mux_1_3 <= din6 when sel(0) = '0' else din7;
mux_1_4 <= din8 when sel(0) = '0' else din9;
mux_1_5 <= din10 when sel(0) = '0' else din11;
mux_1_6 <= din12 when sel(0) = '0' else din13;
mux_1_7 <= din14 when sel(0) = '0' else din15;
mux_1_8 <= din16 when sel(0) = '0' else din17;
mux_1_9 <= din18 when sel(0) = '0' else din19;
mux_1_10 <= din20 when sel(0) = '0' else din21;
mux_1_11 <= din22 when sel(0) = '0' else din23;
mux_1_12 <= din24 when sel(0) = '0' else din25;
mux_1_13 <= din26 when sel(0) = '0' else din27;
mux_1_14 <= din28 when sel(0) = '0' else din29;
mux_1_15 <= din30 when sel(0) = '0' else din31;
mux_1_16 <= din32 when sel(0) = '0' else din33;
mux_1_17 <= din34 when sel(0) = '0' else din35;
mux_1_18 <= din36 when sel(0) = '0' else din37;
mux_1_19 <= din38;

-- Generate level 2 logic
mux_2_0 <= mux_1_0 when sel(1) = '0' else mux_1_1;
mux_2_1 <= mux_1_2 when sel(1) = '0' else mux_1_3;
mux_2_2 <= mux_1_4 when sel(1) = '0' else mux_1_5;
mux_2_3 <= mux_1_6 when sel(1) = '0' else mux_1_7;
mux_2_4 <= mux_1_8 when sel(1) = '0' else mux_1_9;
mux_2_5 <= mux_1_10 when sel(1) = '0' else mux_1_11;
mux_2_6 <= mux_1_12 when sel(1) = '0' else mux_1_13;
mux_2_7 <= mux_1_14 when sel(1) = '0' else mux_1_15;
mux_2_8 <= mux_1_16 when sel(1) = '0' else mux_1_17;
mux_2_9 <= mux_1_18 when sel(1) = '0' else mux_1_19;

-- Generate level 3 logic
mux_3_0 <= mux_2_0 when sel(2) = '0' else mux_2_1;
mux_3_1 <= mux_2_2 when sel(2) = '0' else mux_2_3;
mux_3_2 <= mux_2_4 when sel(2) = '0' else mux_2_5;
mux_3_3 <= mux_2_6 when sel(2) = '0' else mux_2_7;
mux_3_4 <= mux_2_8 when sel(2) = '0' else mux_2_9;

-- Generate level 4 logic
mux_4_0 <= mux_3_0 when sel(3) = '0' else mux_3_1;
mux_4_1 <= mux_3_2 when sel(3) = '0' else mux_3_3;
mux_4_2 <= mux_3_4;

-- Generate level 5 logic
mux_5_0 <= mux_4_0 when sel(4) = '0' else mux_4_1;
mux_5_1 <= mux_4_2;

-- Generate level 6 logic
mux_6_0 <= mux_5_0 when sel(5) = '0' else mux_5_1;

-- Generate level 7 logic
mux_7_0 <= mux_6_0;

-- Generate level 8 logic
mux_8_0 <= mux_7_0;

-- Generate level 9 logic
mux_9_0 <= mux_8_0;

-- output logic
dout <= mux_9_0;

end architecture;
