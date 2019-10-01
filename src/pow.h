// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_POW_H
#define BITCOIN_POW_H

#include <stdint.h>
#include "primitives/block.h"

class CBlockHeader;
class CBlockIndex;
class uint256;
class arith_uint256;

// Define difficulty retarget algorithms
enum DiffMode {
    DIFF_DEFAULT = 0, // Default to invalid 0
    DIFF_BTC = 1,     // Retarget every x blocks (Bitcoin style)
    DIFF_KGW = 2,     // Retarget using Kimoto Gravity Well
    DIFF_DGW = 3,     // Retarget using Dark Gravity Wave v3
};

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader* pblock);

/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckProofOfWork(uint256 hash, unsigned int nBits);
uint256 GetBlockProof(const CBlockIndex& block);

extern const uint32_t POA_BLOCK_PERIOD;
extern unsigned int N_BITS;
//unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader* pblock);

//Check PoA block header consensus rules
bool CheckPrevPoABlockHash(const CBlockHeader& block);

bool CheckPoAMerkleRoot(const CBlock& block, bool* fMutate = NULL);

/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckPoABlockMinedHash(const CBlockHeader& block);

bool CheckPoAContainRecentHash(const CBlock& block);
bool CheckNumberOfAuditedPoSBlocks(const CBlock& block);
bool CheckPoABlockNotContainingPoABlockInfo(const CBlock& block);

bool CheckPoAblockTime(const CBlock& block);
bool CheckPoABlockNotAuditingOverlap(const CBlock& block);


#endif // BITCOIN_POW_H