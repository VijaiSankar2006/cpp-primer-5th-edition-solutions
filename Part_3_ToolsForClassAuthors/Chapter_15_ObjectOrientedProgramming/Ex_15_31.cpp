/************************************************************************************************************************************************************
 * @file Ex_15_31.cpp
 * @brief Exercise 15.31: Given that s1, s2, s3, and s4 are all strings, determine what objects are created in the
 *  following expressions:
 * (a) Query(s1) | Query(s2) & ~ Query(s3);
 * (b) Query(s1) | (Query(s2) & ~ Query(s3));
 * (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
 * @date 2024-02-07
 * 
 * @copyright Copyright (c) 2024
 * 
 *************************************************************************************************************************************************************/

/************************************************************************************************************************************************************
 * (a) Query(s1) | Query(s2) & ~ Query(s3) 
 *     Query q =( Query(s1) | (Query(s2) & (~ Query(S3)) ) )
 *             = ( WordQuery(s1) | (WordQuery(s2) & (~ WordQuery(s3)) )
 *             = OrQuery( WordQuery(s1), AndQuery( WordQuery(S2),NotQuery(Wordquery(s3)) ) )
 * 
 * (b) Query(s1) | (Query(s2) & ~ Query(s3)) 
 *     Query q = OrQuery(WordQuery(s1), AndQuery( WordQuery(S2),NotQuery(WordQuery(s3)) ) )
 *     
 * (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
 *      OrQuery( AndQuery(WordQuery(s1),WordQuery(s2)) , AndQuery(WordQuery(s3),WordQuery(s4)) )
 *   
 *************************************************************************************************************************************************************/