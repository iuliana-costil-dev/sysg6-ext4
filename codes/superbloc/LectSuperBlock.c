#define _LARGEFILE64_SOURCE
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    unsigned int   inode_count;
    unsigned int   block_count;
    unsigned int   reserved_block_count;
    unsigned int   free_block_count;
    unsigned int   free_inode_count;
    unsigned int   first_data_block;
    unsigned int   log_block_size;
    unsigned int   log_frag_size;
    unsigned int   blocks_per_group;
    unsigned int   frags_per_group;
    unsigned int   inodes_per_group;
    unsigned int   mtime;
    unsigned int   wtime;
    unsigned short mnt_count;
    unsigned short max_mnt_count;
    unsigned short magic;
    unsigned short state;
    unsigned short errors;
    unsigned short minor_rev_level;
    unsigned int   lastcheck;
    unsigned int   checkinterval;
    unsigned int   creator_os;
    unsigned int   rev_level;
    unsigned short def_resuid;
    unsigned short def_resgid;
    unsigned int   first_ino;
    unsigned short inode_size;
    unsigned short block_group_nr;
    unsigned int   feature_compat;
    unsigned int   feature_incompat;
    unsigned int   feature_ro_compat;
    unsigned char  uuid[16];
    char           volume_name[16];
    char           last_mounted[64];
    unsigned int   algorithm_usage_bitmap;
    unsigned char  prealloc_blocks;
    unsigned char  prealloc_dir_blocks;
    unsigned short reserved_gdt_blocks;
    unsigned char  journal_uuid[16];
    unsigned int   journal_inum;
    unsigned int   journal_dev;
    unsigned int   last_orphan;
    unsigned int   hash_seed[4];
    unsigned char  journal_backup_type;
    unsigned char  reserved[1024];
} __attribute__ ((packed)) ext4_superblock;

int main ( int argc, char * argv[] )
{	int fd;
	ext4_superblock sb;
	if ( argc != 2 )
		{ printf("usage : LectSuperBlock <pilote>\n");
		  exit(1);
		}
	fd=open(argv[1],O_RDONLY);
	if ( fd < 0)
		{
		  perror(argv[1]);
		  exit(1);
		}
	printf("Infos trouvé dans le superbloc de %s :\n",argv[1]);
	printf("===================================\n");
	lseek64(fd, 1024, SEEK_SET); //the group 0 padding
	read(fd,&sb,1024);
	printf ("L'UUID du systeme: ");
	for (int i = 0; i < 16; i++)
        	printf("%2.2x", sb.uuid[i]);
	printf ("\n");
	printf ("Nombre magique: %x. \n",sb.magic);
	printf ("Numero d'inodes: %d. \n", sb.inode_count);
	printf ("Numero de blocs: %d. \n", sb.block_count);
	printf ("Nombre de blocs reservés (qui ne peuvent être alloués que par le super-utilisateur): %d. \n", sb.reserved_block_count);
	printf ("Numero de blocs libres: %d. \n", sb.free_block_count);
	printf ("Numero d'inodes libres: %d. \n", sb.free_inode_count);
	printf ("Le premier block pour les données: %d. \n", sb.first_data_block);
	printf ("Taille du bloc: %f. \n", pow(2, (10 + sb.log_block_size)));
	printf ("Taille du fragment: %f. \n", pow(2, (10 + sb.log_frag_size)));
	printf ("Numero de blocs par groupe: %d. \n", sb.blocks_per_group);
	printf ("Numero de fragments par groupe: %d. \n", sb.frags_per_group);
	printf ("Numero d'inodes par groupe: %d. \n", sb.inodes_per_group);


	close(fd);
  	exit(0);
}
