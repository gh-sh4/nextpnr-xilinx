/*
 *  nextpnr -- Next Generation Place and Route
 *
 *  Copyright (C) 2019  David Shah <david@symbioticeda.com>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include "nextpnr.h"

NEXTPNR_NAMESPACE_BEGIN

void get_invertible_pins(Context *ctx, std::unordered_map<IdString, std::unordered_set<IdString>> &invertible_pins)
{
    // List of pins that have an IS_x_INVERTED attributed, so we can optimise tie-zero to tie-one for these pins
    // See scripts/invertible_pins.py
    invertible_pins[ctx->id("BUFGCTRL")].insert(ctx->id("CE0"));
    invertible_pins[ctx->id("BUFGCTRL")].insert(ctx->id("CE1"));
    invertible_pins[ctx->id("BUFGCTRL")].insert(ctx->id("S0"));
    invertible_pins[ctx->id("BUFGCTRL")].insert(ctx->id("S1"));
    invertible_pins[ctx->id("BUFGCTRL")].insert(ctx->id("IGNORE0"));
    invertible_pins[ctx->id("BUFGCTRL")].insert(ctx->id("IGNORE1"));
    invertible_pins[ctx->id("BUFHCE")].insert(ctx->id("CE"));
    invertible_pins[ctx->id("FDRE")].insert(ctx->id("C"));
    invertible_pins[ctx->id("FDRE")].insert(ctx->id("R"));
    invertible_pins[ctx->id("FDSE")].insert(ctx->id("C"));
    invertible_pins[ctx->id("FDSE")].insert(ctx->id("S"));
    invertible_pins[ctx->id("FDCE")].insert(ctx->id("C"));
    invertible_pins[ctx->id("FDCE")].insert(ctx->id("CLR"));
    invertible_pins[ctx->id("FDPE")].insert(ctx->id("C"));
    invertible_pins[ctx->id("FDPE")].insert(ctx->id("PRE"));
    invertible_pins[ctx->id("SRL16E")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("SRLC32E")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("BUFGCE")].insert(ctx->id("CE"));
    invertible_pins[ctx->id("BUFGCE")].insert(ctx->id("I"));
    invertible_pins[ctx->id("BUFGCE_DIV")].insert(ctx->id("CE"));
    invertible_pins[ctx->id("BUFGCE_DIV")].insert(ctx->id("CLR"));
    invertible_pins[ctx->id("BUFGCE_DIV")].insert(ctx->id("I"));
    invertible_pins[ctx->id("CFGLUT5")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("ALUMODE[0]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("ALUMODE[1]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("ALUMODE[2]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("ALUMODE[3]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("CARRYIN"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("INMODE[0]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("INMODE[1]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("INMODE[2]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("INMODE[3]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("INMODE[4]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[0]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[1]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[2]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[3]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[4]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[5]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[6]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[7]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("OPMODE[8]"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTALLCARRYIN"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTALUMODE"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTA"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTB"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTCTRL"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTC"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTD"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTINMODE"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTM"));
    invertible_pins[ctx->id("DSP48E2")].insert(ctx->id("RSTP"));
    invertible_pins[ctx->id("FIFO18E2")].insert(ctx->id("RDCLK"));
    invertible_pins[ctx->id("FIFO18E2")].insert(ctx->id("RDEN"));
    invertible_pins[ctx->id("FIFO18E2")].insert(ctx->id("RSTREG"));
    invertible_pins[ctx->id("FIFO18E2")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("FIFO18E2")].insert(ctx->id("WRCLK"));
    invertible_pins[ctx->id("FIFO18E2")].insert(ctx->id("WREN"));
    invertible_pins[ctx->id("FIFO36E2")].insert(ctx->id("RDCLK"));
    invertible_pins[ctx->id("FIFO36E2")].insert(ctx->id("RDEN"));
    invertible_pins[ctx->id("FIFO36E2")].insert(ctx->id("RSTREG"));
    invertible_pins[ctx->id("FIFO36E2")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("FIFO36E2")].insert(ctx->id("WRCLK"));
    invertible_pins[ctx->id("FIFO36E2")].insert(ctx->id("WREN"));
    invertible_pins[ctx->id("HARD_SYNC")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("IDDRE1")].insert(ctx->id("CB"));
    invertible_pins[ctx->id("IDDRE1")].insert(ctx->id("C"));
    invertible_pins[ctx->id("IDELAYE3")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("IDELAYE3")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("ISERDESE3")].insert(ctx->id("CLK_B"));
    invertible_pins[ctx->id("ISERDESE3")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("ISERDESE3")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("LDCE")].insert(ctx->id("CLR"));
    invertible_pins[ctx->id("LDCE")].insert(ctx->id("G"));
    invertible_pins[ctx->id("LDPE")].insert(ctx->id("G"));
    invertible_pins[ctx->id("LDPE")].insert(ctx->id("PRE"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("CLKFBIN"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("CLKIN1"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("CLKIN2"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("CLKINSEL"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("PSEN"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("PSINCDEC"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("PWRDWN"));
    invertible_pins[ctx->id("MMCME3_ADV")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("MMCME3_BASE")].insert(ctx->id("CLKFBIN"));
    invertible_pins[ctx->id("MMCME3_BASE")].insert(ctx->id("CLKIN1"));
    invertible_pins[ctx->id("MMCME3_BASE")].insert(ctx->id("PWRDWN"));
    invertible_pins[ctx->id("MMCME3_BASE")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("CLKFBIN"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("CLKIN1"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("CLKIN2"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("CLKINSEL"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("PSEN"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("PSINCDEC"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("PWRDWN"));
    invertible_pins[ctx->id("MMCME4_ADV")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("ODDRE1")].insert(ctx->id("C"));
    invertible_pins[ctx->id("ODDRE1")].insert(ctx->id("D1"));
    invertible_pins[ctx->id("ODDRE1")].insert(ctx->id("D2"));
    invertible_pins[ctx->id("ODELAYE3")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("ODELAYE3")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("OR2L")].insert(ctx->id("SRI"));
    invertible_pins[ctx->id("OSERDESE3")].insert(ctx->id("CLKDIV"));
    invertible_pins[ctx->id("OSERDESE3")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("OSERDESE3")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("PLLE3_ADV")].insert(ctx->id("CLKFBIN"));
    invertible_pins[ctx->id("PLLE3_ADV")].insert(ctx->id("CLKIN"));
    invertible_pins[ctx->id("PLLE3_ADV")].insert(ctx->id("PWRDWN"));
    invertible_pins[ctx->id("PLLE3_ADV")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("PLLE3_BASE")].insert(ctx->id("CLKFBIN"));
    invertible_pins[ctx->id("PLLE3_BASE")].insert(ctx->id("CLKIN"));
    invertible_pins[ctx->id("PLLE3_BASE")].insert(ctx->id("PWRDWN"));
    invertible_pins[ctx->id("PLLE3_BASE")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("PLLE4_ADV")].insert(ctx->id("CLKFBIN"));
    invertible_pins[ctx->id("PLLE4_ADV")].insert(ctx->id("CLKIN"));
    invertible_pins[ctx->id("PLLE4_ADV")].insert(ctx->id("PWRDWN"));
    invertible_pins[ctx->id("PLLE4_ADV")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("RAM128X1D")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM128X1S")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM256X1D")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM256X1S")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM32M")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM32M16")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM32X1D")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM32X1S")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM32X2S")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM512X1S")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM64M")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM64M8")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM64X1D")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM64X1S")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAM64X8SW")].insert(ctx->id("WCLK"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("CLKARDCLK"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("CLKBWRCLK"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("ENARDEN"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("ENBWREN"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("RSTRAMARSTRAM"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("RSTRAMB"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("RSTREGARSTREG"));
    invertible_pins[ctx->id("RAMB18E2")].insert(ctx->id("RSTREGB"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("CLKARDCLK"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("CLKBWRCLK"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("ENARDEN"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("ENBWREN"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("RSTRAMARSTRAM"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("RSTRAMB"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("RSTREGARSTREG"));
    invertible_pins[ctx->id("RAMB36E2")].insert(ctx->id("RSTREGB"));
    invertible_pins[ctx->id("RX_BITSLICE")].insert(ctx->id("CLK_EXT"));
    invertible_pins[ctx->id("RX_BITSLICE")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("RX_BITSLICE")].insert(ctx->id("RST_DLY_EXT"));
    invertible_pins[ctx->id("RX_BITSLICE")].insert(ctx->id("RST_DLY"));
    invertible_pins[ctx->id("RX_BITSLICE")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("RXTX_BITSLICE")].insert(ctx->id("RX_CLK"));
    invertible_pins[ctx->id("RXTX_BITSLICE")].insert(ctx->id("RX_RST_DLY"));
    invertible_pins[ctx->id("RXTX_BITSLICE")].insert(ctx->id("RX_RST"));
    invertible_pins[ctx->id("RXTX_BITSLICE")].insert(ctx->id("TX_CLK"));
    invertible_pins[ctx->id("RXTX_BITSLICE")].insert(ctx->id("TX_RST_DLY"));
    invertible_pins[ctx->id("RXTX_BITSLICE")].insert(ctx->id("TX_RST"));
    invertible_pins[ctx->id("SYSMONE1")].insert(ctx->id("CONVSTCLK"));
    invertible_pins[ctx->id("SYSMONE1")].insert(ctx->id("DCLK"));
    invertible_pins[ctx->id("SYSMONE4")].insert(ctx->id("CONVSTCLK"));
    invertible_pins[ctx->id("SYSMONE4")].insert(ctx->id("DCLK"));
    invertible_pins[ctx->id("TX_BITSLICE")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("TX_BITSLICE")].insert(ctx->id("RST_DLY"));
    invertible_pins[ctx->id("TX_BITSLICE")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("TX_BITSLICE_TRI")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("TX_BITSLICE_TRI")].insert(ctx->id("RST_DLY"));
    invertible_pins[ctx->id("TX_BITSLICE_TRI")].insert(ctx->id("RST"));
    invertible_pins[ctx->id("URAM288")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("URAM288")].insert(ctx->id("EN_A"));
    invertible_pins[ctx->id("URAM288")].insert(ctx->id("EN_B"));
    invertible_pins[ctx->id("URAM288")].insert(ctx->id("RDB_WR_A"));
    invertible_pins[ctx->id("URAM288")].insert(ctx->id("RDB_WR_B"));
    invertible_pins[ctx->id("URAM288")].insert(ctx->id("RST_A"));
    invertible_pins[ctx->id("URAM288")].insert(ctx->id("RST_B"));
    invertible_pins[ctx->id("URAM288_BASE")].insert(ctx->id("CLK"));
    invertible_pins[ctx->id("URAM288_BASE")].insert(ctx->id("EN_A"));
    invertible_pins[ctx->id("URAM288_BASE")].insert(ctx->id("EN_B"));
    invertible_pins[ctx->id("URAM288_BASE")].insert(ctx->id("RDB_WR_A"));
    invertible_pins[ctx->id("URAM288_BASE")].insert(ctx->id("RDB_WR_B"));
    invertible_pins[ctx->id("URAM288_BASE")].insert(ctx->id("RST_A"));
    invertible_pins[ctx->id("URAM288_BASE")].insert(ctx->id("RST_B"));
}

void get_tied_pins(Context *ctx, std::unordered_map<IdString, std::unordered_map<IdString, bool>> &tied_pins)
{
    // List of pins that are tied to a fixed value when unused.
    // This doesn't include the PS8, due to the large number of tied-zero pins that are implied by the
    // list of Bel pins and dealt with as a special case in arch_place.cc

    for (IdString ram : {ctx->id("RAMB18E2"), ctx->id("RAMB36E2")}) {
        // based on UG573 p37
        for (char port : {'A', 'B'}) {
            tied_pins[ram][ctx->id(std::string("ADDREN") + port)] = true;
            tied_pins[ram][ctx->id(std::string("CASDIMUX") + port)] = false;
            tied_pins[ram][ctx->id(std::string("CASDOMUX") + port)] = false;
            if (ram == ctx->id("RAMB18E2")) {
                tied_pins[ram][ctx->id(std::string("CASDOMUXEN_") + port)] = true;
                tied_pins[ram][ctx->id(std::string("CASOREGIMUXEN_") + port)] = true;
            }

            tied_pins[ram][ctx->id(std::string("CASOREGIMUX") + port)] = false;
        }

        int wea_width = (ram == ctx->id("RAMB18E2") ? 2 : 4);
        int web_width = 4;

        for (int i = 0; i < wea_width; i++)
            tied_pins[ram][ctx->id(std::string("WEA[") + std::to_string(i) + "]")] = true;
        for (int i = 0; i < web_width; i++)
            tied_pins[ram][ctx->id(std::string("WEBWE[") + std::to_string(i) + "]")] = true;

        tied_pins[ram][ctx->id("CLKARDCLK")] = false;
        tied_pins[ram][ctx->id("CLKBWRCLK")] = false;
        tied_pins[ram][ctx->id("ENARDEN")] = false;
        tied_pins[ram][ctx->id("ENBWREN")] = false;
        tied_pins[ram][ctx->id("REGCEAREGCE")] = true;
        tied_pins[ram][ctx->id("REGCEB")] = true;

        tied_pins[ram][ctx->id("RSTRAMARSTRAM")] = false;
        tied_pins[ram][ctx->id("RSTRAMB")] = false;
        tied_pins[ram][ctx->id("RSTREGARSTREG")] = false;
        tied_pins[ram][ctx->id("RSTREGB")] = false;
        tied_pins[ram][ctx->id("SLEEP")] = false;

        if (ram == ctx->id("RAMB36E2")) {
            tied_pins[ram][ctx->id("INJECTSBITERR")] = false;
            tied_pins[ram][ctx->id("INJECTDBITERR")] = false;
            tied_pins[ram][ctx->id("ECCPIPECE")] = true;
        }
    }

    // BUFGCTRL (by experiment)
    for (int i = 0; i < 2; i++) {
        tied_pins[ctx->id("BUFGCTRL")][ctx->id("S" + std::to_string(i))] = false;
        tied_pins[ctx->id("BUFGCTRL")][ctx->id("IGNORE" + std::to_string(i))] = false;
        tied_pins[ctx->id("BUFGCTRL")][ctx->id("CE" + std::to_string(i))] = false;
    }

    // URAM288 (by experiment)
    for (IdString uram : {ctx->id("URAM288"), ctx->id("URAM288_BASE")}) {
        for (char port : {'A', 'B'}) {
            tied_pins[uram][ctx->id(std::string("RST_") + port)] = false;
            tied_pins[uram][ctx->id(std::string("RDB_WR_") + port)] = false;
            tied_pins[uram][ctx->id(std::string("OREG_CE_") + port)] = true;
            tied_pins[uram][ctx->id(std::string("OREG_ECC_CE_") + port)] = true;
            tied_pins[uram][ctx->id(std::string("EN_") + port)] = true;

            tied_pins[uram][ctx->id(std::string("INJECT_SBITERR_") + port)] = false;
            tied_pins[uram][ctx->id(std::string("INJECT_SBITERR_") + port)] = false;

            for (int i = 0; i < 9; i++)
                tied_pins[uram][ctx->id(std::string("BWE_") + port + "[" + std::to_string(i) + "]")] = true;
        }
        tied_pins[uram][ctx->id("SLEEP")] = false;
    }
}

// Get a list of logical pins that have both L and U bel pins that need
// to be connected for a 36-bit BRAM
void get_bram36_ul_pins(Context *ctx, std::vector<std::pair<IdString, std::vector<std::string>>> &ul_pins)
{
    BelId spec_bel;
    for (auto bel : ctx->getBels()) {
        if (ctx->getBelType(bel) == id_RAMB36E2_RAMB36E2) {
            spec_bel = bel;
            break;
        }
    }
    NPNR_ASSERT(spec_bel != BelId());
    std::set<std::string> belpins;
    for (auto &bp : ctx->getBelPins(spec_bel))
        if (ctx->getBelPinType(spec_bel, bp) == PORT_IN)
            belpins.insert(bp.str(ctx));
    for (auto &bp : belpins) {
        std::string bus_suffix = "";
        std::string root_name = bp;
        if (std::isdigit(bp.back())) {
            auto root_end = bp.find_last_not_of("0123456789");
            bus_suffix = bp.substr(root_end + 1);
            root_name = bp.substr(0, root_end + 1);
        }
        if (root_name.back() != 'L')
            continue;
        std::string base_name = root_name.substr(0, root_name.length() - 1);
        std::string complement = base_name + "U" + bus_suffix;
        if (!belpins.count(complement))
            continue;
        std::string logical_name = bus_suffix.empty() ? base_name : (base_name + "[" + bus_suffix + "]");
        ul_pins.emplace_back(ctx->id(logical_name), std::vector<std::string>{bp, complement});
    }
}

NEXTPNR_NAMESPACE_END