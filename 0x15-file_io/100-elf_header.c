#include "main.h"
#include <elf.h>

void print_elf_magic(unsigned char *magic)
{
	int i;
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
	printf("%02x%c", magic[i], (i < EI_NIDENT - 1) ? ' ' : '\n');
	}
}

void print_elf_class(unsigned char elf_class)
{
	const char *class_str = (elf_class == ELFCLASS32) ? "ELF32" : (elf_class == ELFCLASS64) ? "ELF64" : "<unknown>";
	printf("  Class:   %s\n", class_str);
}

void print_elf_data(unsigned char elf_data)
{
	const char *data_str;
	if (elf_data == ELFDATA2LSB)
	{
		data_str = "2's complement, little endian";
	}
	else if (elf_data == ELFDATA2MSB)
	{
		data_str = "2's complement, big endian";
	}
	else
	{
		data_str = "Invalid data encoding";
	}
	printf("  Data:    %s\n", data_str);
}

void print_elf_version(unsigned char elf_version) {
    const char *version_str = (elf_version == EV_CURRENT) ? " (current)" : "";
    printf("  Version: %u%s\n", elf_version, version_str);
}

void print_elf_osabi(unsigned char elf_osabi)
{
	const char *osabi_table[] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	if (elf_osabi < 19)
	{
		printf("  OS/ABI:  %s\n", osabi_table[elf_osabi]);
	}
	else
	{
		printf("  OS/ABI:  <unknown: %u>\n", elf_osabi);
	}
}

void print_elf_abivers(unsigned char elf_abivers)
{
	printf("  ABI Version: %u\n", elf_abivers);
}

void print_elf_type(Elf64_Half elf_type)
{
	const char *type_table[] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	const char *type_str;

	if (elf_type < ET_NUM)
	{
		type_str = type_table[elf_type];
	}
	else if (elf_type >= ET_LOOS && elf_type <= ET_HIOS)
	{
		type_str = "OS Specific";
	}
	else
	{
		type_str = "<unknown>";
	}

	printf("  Type:    %s\n", type_str);
}

void print_elf_entry(unsigned char *entry, int bit_mode)
{
	printf("  Entry point address: ");
	if (bit_mode == 32)
	{
	printf("0x%02x%02x%02x%02x\n", entry[3], entry[2], entry[1], entry[0]);
	}
	else if (bit_mode == 64) {
		printf("0x%02x%02x%02x%02x%02x%02x%02x%02x\n", entry[7], entry[6], entry[5], entry[4], entry[3], entry[2], entry[1], entry[0]);
	}
}

int main(int argc, char *argv[])
{
	int fd;
	unsigned char header[EI_NIDENT];
	ssize_t num_bytes;
	int bit_mode;
	unsigned char entry[8];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
    	if (fd == -1)
	{
		perror("Error: Can't read from file");
		exit(98);
	}

	num_bytes = read(fd, header, sizeof(header));
	if (num_bytes != sizeof(header))
	{
		perror("Error: Can't read ELF header");
		close(fd);
		exit(98);
	}

	print_elf_magic(header);
	print_elf_class(header[EI_CLASS]);
	print_elf_data(header[EI_DATA]);
	print_elf_version(header[EI_VERSION]);
	print_elf_osabi(header[EI_OSABI]);
	print_elf_abivers(header[EI_ABIVERSION]);
	print_elf_type(*(Elf64_Half*)(header + 16));
	lseek(fd, 24, SEEK_SET);

	bit_mode = (header[EI_CLASS] == ELFCLASS32) ? 32 : 64;
	num_bytes = read(fd, entry, bit_mode / 8);
	if (num_bytes != bit_mode / 8)
	{
		perror("Error: Can't read entry point");
		close(fd);
		exit(98);
	}

	print_elf_entry(entry, bit_mode);
	close(fd);
	return 0;
}

