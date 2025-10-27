#include "Arduino.h"
#include "SPI.h"

#define BURST 0x40
#define READ 0x80

class CC1200 {
    public:
        CC1200(SPIClass* SPI, SPISettings settings, int cs);
        void begin();
        byte status();
        void simpleConfig();
        void narrowConfig();
        bool ready();
        byte partnum();
        bool testTx();
        void Tx(uint8_t *data, uint8_t len);
        void Rx(uint8_t len);
        void testRx();
        byte avail();
        void read(byte* buf, byte len);
        byte reset();
        int8_t rssi();
        float fullrssi();
        void sineWave();
    private:
        SPIClass* _SPI;
        SPISettings _settings;
        void _writeReg(unsigned int reg, byte val);
        byte _readReg(unsigned int reg);
        byte _strobe(byte cmd);
        int _cs;
};
