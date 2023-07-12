#include "main.h"

/**
 * display_elf_header - Displays the information contained in the ELF header.
 * @header: Pointer to the ELF header structure.
 */

void display_elf_header(Elf64_Ehdr *header)
{
	printf("Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class: %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("Data: %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
						((header->e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" : "Invalid data encoding"));
	printf("Version: %d\n", header->e_ident[EI_VERSION]);

	printf("OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("HP-UX\n"); break;
		case ELFOSABI_NETBSD: printf("NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("Linux\n"); break;
		case ELFOSABI_SOLARIS: printf("Solaris\n"); break;
		case ELFOSABI_AIX: printf("AIX\n"); break;
		case ELFOSABI_IRIX: printf("IRIX\n"); break;
		case ELFOSABI_FREEBSD: printf("FreeBSD\n"); break;
		case ELFOSABI_TRU64: printf("Tru64 UNIX\n"); break;
		case ELFOSABI_MODESTO: printf("Novell Modesto\n"); break;
		case ELFOSABI_OPENBSD: printf("OpenBSD\n"); break;
		case ELFOSABI_ARM_AEABI: printf("ARM EABI\n"); break;
		case ELFOSABI_ARM: printf("ARM\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone (embedded) application\n"); break;
		default: printf("Unknown\n"); break;
	}

	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type: ");
	switch (header->e_type)
	{
		case ET_NONE: printf("None\n"); break;
		case ET_REL: printf("Relocatable\n"); break;
		case ET_EXEC: printf("Executable\n"); break;
		case ET_DYN: printf("Shared object\n"); break;
		case ET_CORE: printf("Core\n"); break;
		default: printf("Unknown\n"); break;
	}

	printf("Entry point address: %lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point.
 * @argc: The number of command line arguments.
 * @argv: An array of command line argument strings.
 *
 * Return: 0 on success, or the corresponding error code.
 */

int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Failed to read ELF header\n");
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: File '%s' is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	display_elf_header(&header);

	close(fd);
	return (0);
}
