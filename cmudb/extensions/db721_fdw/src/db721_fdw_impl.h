// clang-format off
#include "../../../../src/include/postgres.h"
#include "../../../../src/include/fmgr.h"
#include "../../../../src/include/foreign/fdwapi.h"
// clang-format on

extern void db721_GetForeignRelSize(PlannerInfo *root, RelOptInfo *baserel, Oid foreigntableid);
extern void db721_GetForeignPaths(PlannerInfo *root, RelOptInfo *baserel, Oid foreigntableid);
extern ForeignScan *db721_GetForeignPlan(PlannerInfo *root, RelOptInfo *baserel, Oid foreigntableid, ForeignPath *best_path, List *tlist, List *scan_clauses, Plan *outer_plan);
extern void db721_BeginForeignScan(ForeignScanState *node, int eflags);
extern TupleTableSlot *db721_IterateForeignScan(ForeignScanState *node);
extern void db721_ReScanForeignScan(ForeignScanState *node);
extern void db721_EndForeignScan(ForeignScanState *node);
