#include "expr/pdb_db_int.h"
#include "expr/parse.h"
#include <stack>
#include <vector>
#include "expr/sql_parser.h"
#include "expr/expr_item.h"
#include "expr/column_item.h"
#include "expr/group_opt.h"
#include "expr/orderby_opt.h"
#include "expr/limit_opt.h"

void pdbSetError(SQLParser* pParse, const char* pErrMsg)
{
  if (pParse != nullptr)
  {
    pParse->SetError();
  }
}

void pdbDelete(SQLParser* pParse, Token* pTabName, ExprItem* pWhere)
{
  if (pParse != nullptr)
  {
    pParse->SetDelete(pTabName, pWhere);
  }
}

void pdbDropTable(SQLParser* pParse, Token* pTabToken)
{
  if (pParse != nullptr)
  {
    pParse->SetDropTable(pTabToken);
  }
}

void pdbAttachTable(SQLParser* pParse, Token* pTabToken)
{
  if (pParse != nullptr)
  {
    pParse->SetAttachTable(pTabToken);
  }
}

void pdbDetachTable(SQLParser* pParse, Token* pTabToken)
{
  if (pParse != nullptr)
  {
    pParse->SetDetachTable(pTabToken);
  }
}

void pdbAttachFile(SQLParser* pParse, Token* pTabName, Token* pDate, Token* pType)
{
  if (pParse != nullptr)
  {
    pParse->SetAttachFile(pTabName, pDate, pType);
  }
}

void pdbDetachFile(SQLParser* pParse, Token* pTabName, Token* pDate)
{
  if (pParse != nullptr)
  {
    pParse->SetDetachFile(pTabName, pDate);
  }
}

void pdbDropFile(SQLParser* pParse, Token* pTabName, Token* pDate)
{
  if (pParse != nullptr)
  {
    pParse->SetDropFile(pTabName, pDate);
  }
}

void pdbSelect(SQLParser* pParse, ExprList* pSelList, Token* pSrcTab, 
  ExprItem* pWhere, GroupOpt* pGroup, OrderByOpt* pOrderBy, LimitOpt* pLimit)
{
  if (pParse != nullptr)
  {
    pParse->SetQuery(pSelList, pSrcTab, pWhere, pGroup, pOrderBy, pLimit);
  }
}

void pdbInsert(SQLParser* pParse, Token* pTabToken, ExprList* pColList, ExprList* pValList)
{
  if (pParse != nullptr)
  {
    pParse->SetInsert(pTabToken, pColList, pValList);
  }
}

void pdbCreateTable(SQLParser* pParse, Token* pTabName, ColumnList* pColList)
{
  if (pParse != nullptr)
  {
    pParse->SetCreateTable(pTabName, pColList);
  }
}

void pdbAddUser(SQLParser* pParse, Token* pNameToken, Token* pPwdToken)
{
  if (pParse != nullptr)
  {
    pParse->SetAddUser(pNameToken, pPwdToken);
  }
}

void pdbChangePwd(SQLParser* pParse, Token* pNameToken, Token* pPwdToken)
{
  if (pParse != nullptr)
  {
    pParse->SetChangePwd(pNameToken, pPwdToken);
  }
}

void pdbChangeRole(SQLParser* pParse, Token* pNameToken, Token* pRoleToken)
{
  if (pParse != nullptr)
  {
    pParse->SetChangeRole(pNameToken, pRoleToken);
  }
}

void pdbDropUser(SQLParser* pParse, Token* pNameToken)
{
  if (pParse != nullptr)
  {
    pParse->SetDropUser(pNameToken);
  }
}