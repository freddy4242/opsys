
extern "C"{
    #include "system.h"
    //#include "memory/memory.h"
    #include "common.h"
    #include "interrupts.h"
    #include "input.h"
    //#include "song.h"
    #include "string.h"
    #include "pit.h"
}


// Existing global operator new overloads
//void* operator new(size_t size) {
  //  return malloc(size);
//}

//void* operator new[](size_t size) {
  //  return malloc(size);
//}

// Existing global operator delete overloads
//void operator delete(void* ptr) noexcept {
  //  free(ptr);
//}

//void operator delete[](void* ptr) noexcept {
  //  free(ptr);
//}

// Add sized-deallocation functions
//void operator delete(void* ptr, size_t size) noexcept {
   // (void)size; // Size parameter is unused, added to match required signature
  //  free(ptr);
//}

//void operator delete[](void* ptr, size_t size) noexcept {
    //(void)size; // Size parameter is unused, added to match required signature
    //free(ptr);
//}
extern "C" int kernel_main(void);
int kernel_main(){

    
    // Set up interrupt handlers
    register_interrupt_handler(1, [](registers_t* regs, void* context) {
        printf("Interrupt 1 - OK\n");
    }, NULL);

    register_interrupt_handler(2, [](registers_t* regs, void* context) {
        printf("Interrupt 2 - OK\n");
    }, NULL);
    register_interrupt_handler(3, [](registers_t* regs, void* context) {
        printf("Interrupt 3 - OK\n");
    }, NULL);



    // Trigger interrupts to test handlers
    //asm volatile ("int $0x1");
    //asm volatile ("int $0x2");
    //asm volatile ("int $0x3");



    // Enable interrupts
    asm volatile("sti");

    
    // Register IRQ handler for keyboard (IRQ1)
    register_irq_handler(IRQ1, [](registers_t*, void*) {
        // Read from keyboard
        unsigned char scan_code = inb(0x60);
        char f = scancode_to_ascii(&scan_code);

        printf("%c", f);

        // Disable
        asm volatile("cli");
    }, NULL);

    
/*

    Song* songs[] = {

        new Song({battlefield_1942_theme, sizeof(battlefield_1942_theme) / sizeof(Note)}),
        new Song({starwars_theme, sizeof(starwars_theme) / sizeof(Note)}),
        new Song({music_1, sizeof(music_1) / sizeof(Note)}),
        new Song({music_6, sizeof(music_6) / sizeof(Note)}),
        new Song({music_5, sizeof(music_5) / sizeof(Note)}),
        new Song({music_4, sizeof(music_4) / sizeof(Note)}),
        new Song({music_3, sizeof(music_3) / sizeof(Note)}),
        new Song({music_2, sizeof(music_2) / sizeof(Note)})
    };
    uint32_t n_songs = sizeof(songs) / sizeof(Song*);

    // Create a song player and play each song
    SongPlayer* player = create_song_player();
    for(uint32_t i = 0; i < n_songs; i++) {
        printf("Playing Song...\n");
        player->play_song(songs[i]);
        printf("Finished playing the song.\n");
    }
*/
    // Main loop
    printf("Kernel main loop\n");
    while(true) {
        // Kernel main tasks
    }

    // This part will not be reached
    printf("Done!\n");
    return 0;
}