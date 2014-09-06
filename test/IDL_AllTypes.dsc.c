#include "IDL_AllTypes.dsc.h"

int DSCINIT_AllTypes( AllTypes *pst )
{
	int	index[10] = { 0 } ; index[0] = 0 ;
	memset( pst , 0x00 , sizeof(AllTypes) );
	return 0;
}

int DSCNETORDER_AllTypes( AllTypes *pst )
{
	int	index[10] = { 0 } ; index[0] = 0 ;
	pst->n2=(short)htons((unsigned short)(pst->n2));
	pst->n4=(int)htonl((unsigned int)(pst->n4));
	pst->n8=(longlong)HTONLL((unsigned longlong)(pst->n8));
	pst->u2=htons(pst->u2);
	pst->u4=htonl(pst->u4);
	pst->u8=HTONLL(pst->u8);
	return 0;
}

int DSCHOSTORDER_AllTypes( AllTypes *pst )
{
	int	index[10] = { 0 } ; index[0] = 0 ;
	pst->n2=(short)ntohs((unsigned short)(pst->n2));
	pst->n4=(int)ntohl((unsigned int)(pst->n4));
	pst->n8=(longlong)NTOHLL((unsigned longlong)(pst->n8));
	pst->u2=ntohs(pst->u2);
	pst->u4=ntohl(pst->u4);
	pst->u8=NTOHLL(pst->u8);
	return 0;
}

int DSCSERIALIZE_COMPACT_AllTypes( AllTypes *pst , char *buf , int *p_len )
{
	char	*ptr = buf ;
	int	len = 0 ;
	int	index[10] = { 0 } ; index[0] = 0 ;
	
	
	/* n1 */
	(*ptr) = pst->n1 ;
	len++; ptr++;
	
	/* n2 */
	{ short s; s=(short)htons((unsigned short)(pst->n2)); memcpy( ptr , (char*)&s , 2 ); }
	len+=2; ptr+=2;
	
	/* n4 */
	{ int i; i=(int)htonl((unsigned int)(pst->n4)); memcpy( ptr , (char*)&i , 4 ); }
	len+=4; ptr+=4;
	
	/* n8 */
	{ longlong ll; ll=(longlong)HTONLL((unsigned longlong)(pst->n8)); memcpy( ptr , (char*)&ll , 8 ); }
	len+=8; ptr+=8;
	
	/* u1 */
	(*ptr) = (char)pst->u1 ;
	len++; ptr++;
	
	/* u2 */
	{ short s; s=htons(pst->u2); memcpy( ptr , (char*)&s , 2 ); }
	len+=2; ptr+=2;
	
	/* u4 */
	{ int i; i=htonl(pst->u4); memcpy( ptr , (char*)&i , 4 ); }
	len+=4; ptr+=4;
	
	/* u8 */
	{ longlong ll; ll=HTONLL(pst->u8); memcpy( ptr , (char*)&ll , 8 ); }
	len+=8; ptr+=8;
	
	/* f4 */
	memcpy( ptr , (char*)&(pst->f4) , 4 );
	len+=4; ptr+=4;
	
	/* f8 */
	memcpy( ptr , (char*)&(pst->f8) , 8 );
	len+=8; ptr+=8;
	
	/* ch */
	(*ptr) = pst->ch ;
	len++; ptr++;
	
	/* uch */
	(*ptr) = (char)pst->uch ;
	len++; ptr++;
	
	/* str32 */
	memcpy( ptr , pst->str32 , 32 );
	len+=32; ptr+=32;
	
	/* str1024 */
	memcpy( ptr , pst->str1024 , 1024 );
	len+=1024; ptr+=1024;
	
	if( p_len ) (*p_len) = len ;
	
	return 0;
}

int DSCDESERIALIZE_COMPACT_AllTypes( char *buf , int *p_len , AllTypes *pst )
{
	char	*ptr = buf ;
	int	len = 0 ;
	int	index[10] = { 0 } ; index[0] = 0 ;
	
	
	/* n1 */
	pst->n1 = (*ptr) ;
	len++; ptr++;
	
	/* n2 */
	memcpy( (char*)&(pst->n2) , ptr , 2 ); pst->n2=(short)htons((unsigned short)(pst->n2));
	len+=2; ptr+=2;
	
	/* n4 */
	memcpy( (char*)&(pst->n4) , ptr , 4 ); pst->n4=(int)htonl((unsigned int)(pst->n4));
	len+=4; ptr+=4;
	
	/* n8 */
	memcpy( (char*)&(pst->n8) , ptr , 8 ); pst->n8=(longlong)HTONLL((unsigned longlong)(pst->n8));
	len+=8; ptr+=8;
	
	/* u1 */
	pst->u1 = (unsigned char)(*ptr) ;
	len++; ptr++;
	
	/* u2 */
	memcpy( (char*)&(pst->u2) , ptr , 2 ); pst->u2=htons(pst->u2);
	len+=2; ptr+=2;
	
	/* u4 */
	memcpy( (char*)&(pst->u4) , ptr , 4 ); pst->u4=htonl(pst->u4);
	len+=4; ptr+=4;
	
	/* u8 */
	memcpy( (char*)&(pst->u8) , ptr , 8 ); pst->u8=HTONLL(pst->u8);
	len+=8; ptr+=8;
	
	/* f4 */
	memcpy( (char*)&(pst->f4) , ptr , 4 );
	len+=4; ptr+=4;
	
	/* f8 */
	memcpy( (char*)&(pst->f8) , ptr , 8 );
	len+=8; ptr+=8;
	
	/* ch */
	pst->ch = (char)(*ptr) ;
	len++; ptr++;
	
	/* uch */
	pst->uch = (unsigned char)(*ptr) ;
	len++; ptr++;
	
	/* str32 */
	memcpy( pst->str32 , ptr , 32 );
	len+=32; ptr+=32;
	
	/* str1024 */
	memcpy( pst->str1024 , ptr , 1024 );
	len+=1024; ptr+=1024;
	
	if( p_len ) (*p_len) = len ;
	
	return 0;
}

int DSCSERIALIZE_COMPRESS_AllTypes( AllTypes *pst , char *buf , int *p_len )
{
	char	*ptr = buf ;
	int	len = 0 ;
	int	index[10] = { 0 } ; index[0] = 0 ;
	
	/* n1 */
	(*ptr) = pst->n1 ;
	len++; ptr++;
	
	/* n2 */
	{ short s; s=(short)htons((unsigned short)(pst->n2)); memcpy( ptr , (char*)&s , 2 ); }
	len+=2; ptr+=2;
	
	/* n4 */
	COMPRESS_INT4( pst->n4 , ptr , len )
	
	/* n8 */
	COMPRESS_INT8( pst->n8 , ptr , len )
	
	/* u1 */
	(*ptr) = (char)pst->u1 ;
	len++; ptr++;
	
	/* u2 */
	{ short s; s=htons(pst->u2); memcpy( ptr , (char*)&s , 2 ); }
	len+=2; ptr+=2;
	
	/* u4 */
	COMPRESS_UINT4( pst->u4 , ptr , len )
	
	/* u8 */
	COMPRESS_UINT8( pst->u8 , ptr , len )
	
	/* f4 */
	memcpy( ptr , (char*)&(pst->f4) , 4 );
	len+=4; ptr+=4;
	
	/* f8 */
	memcpy( ptr , (char*)&(pst->f8) , 8 );
	len+=8; ptr+=8;
	
	/* ch */
	(*ptr) = pst->ch ;
	len++; ptr++;
	
	/* uch */
	(*ptr) = (char)pst->uch ;
	len++; ptr++;
	
	/* str32 */
	{
	unsigned int size=strlen(pst->str32);
	COMPRESS_UINT4( size , ptr , len )
	memcpy( ptr , pst->str32 , size );
	len+=size; ptr+=size;
	}
	
	/* str1024 */
	{
	unsigned int size=strlen(pst->str1024);
	COMPRESS_UINT4( size , ptr , len )
	memcpy( ptr , pst->str1024 , size );
	len+=size; ptr+=size;
	}
	
	if( p_len ) (*p_len) = len ;
	
	return 0;
}

int DSCDESERIALIZE_COMPRESS_AllTypes( char *buf , int *p_len , AllTypes *pst )
{
	char	*ptr = buf ;
	int	len = 0 ;
	int	index[10] = { 0 } ; index[0] = 0 ;
	
	/* n1 */
	pst->n1 = (*ptr) ;
	len++; ptr++;
	
	/* n2 */
	memcpy( (char*)&(pst->n2) , ptr , 2 ); pst->n2=(short)htons((unsigned short)(pst->n2));
	len+=2; ptr+=2;
	
	/* n4 */
	UNCOMPRESS_INT4( ptr , len , pst->n4 )
	
	/* n8 */
	UNCOMPRESS_INT8( ptr , len , pst->n8 )
	
	/* u1 */
	pst->u1 = (unsigned char)(*ptr) ;
	len++; ptr++;
	
	/* u2 */
	memcpy( (char*)&(pst->u2) , ptr , 2 ); pst->u2=htons(pst->u2);
	len+=2; ptr+=2;
	
	/* u4 */
	UNCOMPRESS_UINT4( ptr , len , pst->u4 )
	
	/* u8 */
	UNCOMPRESS_UINT8( ptr , len , pst->u8 )
	
	/* f4 */
	memcpy( (char*)&(pst->f4) , ptr , 4 );
	len+=4; ptr+=4;
	
	/* f8 */
	memcpy( (char*)&(pst->f8) , ptr , 8 );
	len+=8; ptr+=8;
	
	/* ch */
	pst->ch = (char)(*ptr) ;
	len++; ptr++;
	
	/* uch */
	pst->uch = (unsigned char)(*ptr) ;
	len++; ptr++;
	
	/* str32 */
	{
	unsigned int size ;
	UNCOMPRESS_UINT4( ptr , len , size )
	memcpy( pst->str32 , ptr , size );
	len+=size; ptr+=size;
	}
	
	/* str1024 */
	{
	unsigned int size ;
	UNCOMPRESS_UINT4( ptr , len , size )
	memcpy( pst->str1024 , ptr , size );
	len+=size; ptr+=size;
	}
	
	if( p_len ) (*p_len) = len ;
	
	return 0;
}